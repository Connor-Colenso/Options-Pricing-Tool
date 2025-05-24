#include "AdvBinomial.hpp"
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>


float Binomial(
    const float volatility,
    const float risk_free_rate,
    const float strike,
    const float spot_price,
    const float time_period,
    const int steps,
    const std::function<float(float, float)> payoff) {

    // Calculate parameters for the binomial tree
    const float dt = time_period / steps;
    const float u = expf(volatility * sqrtf(dt));               // Up factor
    const float d = 1 / u;                                      // Down factor
    const float discount = expf(-risk_free_rate * dt);          // Discount factor
    const float p = (expf(risk_free_rate * dt) - d) / (u - d);  // Risk-neutral probability

    // Precalculate spot prices at each step
    std::vector<float> spot_prices(steps + 1);
    for (int i = 0; i <= steps; ++i) {
        spot_prices[i] = spot_price * powf(u, steps - i) * powf(d, i);
    }

    // Create a vector to hold the option values at each node (1D for space efficiency)
    std::vector<float> option_values(steps + 1);

    // Initialize option values at maturity (using put option as example)
    for (int i = 0; i <= steps; ++i) {
        option_values[i] = payoff(strike, spot_prices[i]);
    }

    // Step backwards through the tree
    for (int j = steps - 1; j >= 0; --j) {
        for (int i = 0; i <= j; ++i) {
            // Update spot price for this node
            spot_prices[i] = spot_price * powf(u, j - i) * powf(d, i);

            // Calculate option value at this node (use max for American option)
            float early_exercise_value = payoff(strike, spot_prices[i]);
            float hold_value = discount * (p * option_values[i] + (1 - p) * option_values[i + 1]);
            option_values[i] = std::max(early_exercise_value, hold_value);
        }
    }

    // The option value at the root of the tree
    return option_values[0];
}
