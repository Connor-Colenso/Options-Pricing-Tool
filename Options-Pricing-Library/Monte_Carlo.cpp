#include "Options-Pricing-Lib.h"

void Monte_Carlo_Core(const int number_of_simulations, const int time_steps_per_simulation, const float strike, const float risk_free_interest_rate, const float continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array), int thread_index, std::vector<float>& thread_output_vector) {

    std::vector<float> array(time_steps_per_simulation);

    float sum_payoff = 0;
    float discount_factor = std::exp(-(risk_free_interest_rate - continuous_dividend_yield) * time_until_option_expiry);

    for (int i = 0; i < number_of_simulations; i++) {
        Utility::Geometric_Brownian_Motion(array, time_steps_per_simulation, spot_price_of_underlying, time_until_option_expiry, risk_free_interest_rate - continuous_dividend_yield, volatility);
        sum_payoff += (*payoff_function)(strike, array) * discount_factor;
    }

    thread_output_vector[thread_index] = sum_payoff;
}


float Monte_Carlo(const int number_of_simulations, const int time_steps_per_simulation, const float& strike, const float risk_free_interest_rate, const float& continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array), int thread_override = -1) {
    
    int total_threads = std::thread::hardware_concurrency();
    
    if (thread_override != -1) {
        total_threads = thread_override;
    }
    
    int simulations_per_thread = number_of_simulations / total_threads;
    int simulations_remaining = number_of_simulations;
    std::vector<float> thread_output_vector(total_threads);
    std::vector<std::thread> threads;
    
    int thread_index = 0;
    
    while(simulations_remaining > 0) {
        
        if (simulations_remaining < simulations_per_thread) {
            simulations_per_thread = simulations_remaining;
        }
        
        threads.push_back(std::thread(Monte_Carlo_Core,
                                      simulations_per_thread,
                                      time_steps_per_simulation,
                                      strike,
                                      risk_free_interest_rate,
                                      continuous_dividend_yield,
                                      time_until_option_expiry,
                                      volatility,
                                      spot_price_of_underlying,
                                      payoff_function,
                                      thread_index,
                                      std::ref(thread_output_vector)));
        thread_index++;
        simulations_remaining -= simulations_per_thread;
    }

    for(auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    
    float sum = std::accumulate(thread_output_vector.begin(),
                                thread_output_vector.end(),
                                0.0);
    
    return sum / number_of_simulations;
}