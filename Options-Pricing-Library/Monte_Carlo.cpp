#include "Options-Pricing-Lib.h"

namespace {

    std::vector<std::vector<float>> memory_cache;

    void Monte_Carlo_Core(std::vector<float>& gbm, int simulations_per_thread, const int time_steps_per_simulation, const float strike, const float risk_free_interest_rate, const float continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array), int thread_index, std::vector<float>& thread_output_vector) {

        float sum_payoff = 0;
        const float discount_factor = std::exp(-(risk_free_interest_rate - continuous_dividend_yield) * time_until_option_expiry);

        // For use in GBM/BM.
        float pre_t_division = time_until_option_expiry / (float)time_steps_per_simulation;
        float pre_calc_drift = (risk_free_interest_rate - continuous_dividend_yield) - 0.5f * volatility * volatility;

        for (int i = 0; i < simulations_per_thread; i++) {
            Utility::Geometric_Brownian_Motion(gbm, spot_price_of_underlying, time_until_option_expiry, risk_free_interest_rate - continuous_dividend_yield, volatility, pre_t_division, pre_calc_drift);
            sum_payoff += (*payoff_function)(strike, gbm) * discount_factor;
        }

        thread_output_vector[thread_index] = sum_payoff;
    }
}


float Monte_Carlo(const int number_of_simulations, const int time_steps_per_simulation, const float& strike, const float risk_free_interest_rate, const float& continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array), int thread_override) {
    
    int total_threads = std::thread::hardware_concurrency();
    
    if (thread_override != -1) {
        total_threads = thread_override;
    }
    
    int simulations_per_thread = number_of_simulations / total_threads;
    int simulations_remaining = number_of_simulations;
    std::vector<float> thread_output_vector(total_threads+1);
    std::vector<std::jthread> threads;
    
    int thread_index = 0;
    

    if (memory_cache.size() == 0) {
        for (int i = 0; i < total_threads + 1; i++) {
            memory_cache.emplace_back(time_steps_per_simulation);
        }
    }

    while(simulations_remaining > 0) {
        
        if (simulations_remaining < simulations_per_thread) {
            simulations_per_thread = simulations_remaining;
        }

        threads.emplace_back(Monte_Carlo_Core,
            std::ref(memory_cache[thread_index]),
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
            std::ref(thread_output_vector));

        //threads.emplace_back();

        thread_index++;
        simulations_remaining -= simulations_per_thread;
    }

    for(auto& thread : threads) {
        thread.join();
    }
    
    const float sum = std::accumulate(thread_output_vector.begin(),
                                thread_output_vector.end(),
                                0.0f);
    
    return sum / number_of_simulations;
}
