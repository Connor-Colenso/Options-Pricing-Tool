#include "Monte_Carlo.hpp"
#include "Brownian_Motion.h"

namespace {

    std::vector<std::vector<float>> memory_cache;

    float Monte_Carlo_Core(const int simulations_per_thread, const int time_steps_per_simulation, const float strike, const float risk_free_interest_rate, const float continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, std::function<float(const float&, const std::vector<float>&)> payoff_function, const int thread_index) {

        std::vector<float>& gbm = memory_cache[thread_index];

        float sum_payoff = 0;
        const float discount_factor = std::expf(-(risk_free_interest_rate - continuous_dividend_yield) * time_until_option_expiry);

        // For use in GBM/BM.
        const float pre_t_division = time_until_option_expiry / (float)time_steps_per_simulation;
        const float pre_calc_drift = (risk_free_interest_rate - continuous_dividend_yield) - 0.5f * volatility * volatility;

        for (int i = 0; i < simulations_per_thread; i++) {
            Utility::Geometric_Brownian_Motion(gbm, spot_price_of_underlying, time_until_option_expiry, risk_free_interest_rate - continuous_dividend_yield, volatility, pre_t_division, pre_calc_drift);
            sum_payoff += payoff_function(strike, gbm) * discount_factor;
        }

        return sum_payoff;
    }
}


float Monte_Carlo(const int number_of_simulations, const int time_steps_per_simulation, const float& strike, const float risk_free_interest_rate, const float& continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array)) {
    
    const int total_threads = std::thread::hardware_concurrency();
    
    int simulations_per_thread = number_of_simulations / total_threads;
    int simulations_remaining = number_of_simulations;
    std::vector<std::future<float>> futures;
    
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

        futures.emplace_back(std::async(std::launch::async, Monte_Carlo_Core,
            simulations_per_thread,
            time_steps_per_simulation,
            strike,
            risk_free_interest_rate,
            continuous_dividend_yield,
            time_until_option_expiry,
            volatility,
            spot_price_of_underlying,
            payoff_function,
            thread_index));

        thread_index++;
        simulations_remaining -= simulations_per_thread;
    }

    float sum = 0;
    for(auto& future : futures) {
        sum += future.get();
    }
    
    return sum / number_of_simulations;
}
