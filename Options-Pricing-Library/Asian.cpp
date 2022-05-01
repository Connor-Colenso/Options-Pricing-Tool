#include "Options-Pricing-Lib.h"

namespace Asian {
    float Monte_Carlo(const int& number_of_simulations, const int& time_steps_per_simulation, const float& strike, const float& risk_free_interest_rate, const float& continuous_dividend_yield, const float& time_until_option_expiry, const float& volatility, const float& spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array)) {

        std::vector<float> array(number_of_simulations);

        float sum_payoff = 0;
        float discount_factor = std::exp(-(risk_free_interest_rate - continuous_dividend_yield) * time_until_option_expiry);

        for (int i = 0; i < number_of_simulations; i++) {
            Utility::Geometric_Brownian_Motion(array, time_steps_per_simulation, spot_price_of_underlying, time_until_option_expiry, risk_free_interest_rate - continuous_dividend_yield, volatility);
            sum_payoff += (*payoff_function)(strike, array) * discount_factor;
        }
        
        return sum_payoff / number_of_simulations;
    }
}