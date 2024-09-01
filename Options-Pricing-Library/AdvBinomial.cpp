#include "AdvBinomial.hpp"
#include <algorithm>

float Binomial(const float volatility, const float risk_free_interest_rate, const float strike, const float spot_price, const float time_period, const int steps) {
    // Calculate parameters for the binomial tree
    float dt = time_period / steps;              // Time step
    float u = exp(volatility * sqrt(dt));       // Up factor
    float d = 1 / u;                            // Down factor
    float p = (exp(risk_free_interest_rate * dt) - d) / (u - d); // Risk-neutral probability

    // Create a 2D vector to hold the option values
    std::vector<std::vector<float>> option_values(steps + 1, std::vector<float>(steps + 1));

    // Initialize the option values at maturity
    for (int i = 0; i <= steps; ++i) {
        float price_at_maturity = spot_price * pow(u, steps - i) * pow(d, i);
        option_values[i][steps] = std::max(price_at_maturity - strike, 0.0f); // Payoff of the call option
    }

    // Iterate backward through the tree
    for (int j = steps - 1; j >= 0; --j) {
        for (int i = 0; i <= j; ++i) {
            float price_up = option_values[i][j + 1];
            float price_down = option_values[i + 1][j + 1];
            float price_at_node = exp(-risk_free_interest_rate * dt) * (p * price_up + (1 - p) * price_down);
            float spot_price_at_node = spot_price * pow(u, j - i) * pow(d, i);
            option_values[i][j] = std::max(price_at_node, spot_price_at_node - strike); // American call option value
        }
    }

    // The option value at the root of the tree
    return option_values[0][0];
}