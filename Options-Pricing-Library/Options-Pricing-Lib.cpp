// Options-Pricing-Library.cpp : Defines the functions for the static library.
//

#include "Options-Pricing-Lib.h"

void Brownian_Motion(std::vector<float>& array, const int& n) {
    // Sample random values from a standardised normal distribution.
    std::random_device rd{};
    std::mt19937 gen{ rd() };
    std::normal_distribution<> d{ 0, 1 };

    float tmp = 0;
    float dt = (float) std::sqrt(1.0 / (float)(n));

    for (int i = 0; i < (n); ++i) {
        array[i] = tmp;
        tmp += d(gen) * dt;
    }
}
void Geometric_Brownian_Motion(std::vector<float>& array, const int& n, const float& x0, const float& t, const float& mu, const float& sigma) {

    Brownian_Motion(array, n);

    float t_counter = 0;
    float pre_t_division = t / (float) n;

    float pre_calc_drift = mu - 0.5 * sigma * sigma;

    for (int i = 0; i < n; ++i) {
        array[i] = x0 * std::exp(pre_calc_drift * t_counter + array[i] * sigma);
        t_counter += pre_t_division;
    }
}

namespace Payoff {
    float Payoff::European_Put(const float strike, const float underlying_price_at_expiry) {
        return (strike - underlying_price_at_expiry) <= 0 ? 0 : (strike - underlying_price_at_expiry);
    }
    float Payoff::European_Call(const float strike, const float underlying_price_at_expiry) {
        return (underlying_price_at_expiry - strike) <= 0 ? 0 : (underlying_price_at_expiry - strike);
    }
    float Payoff::European_Chooser(const float strike, const float underlying_price_at_expiry) {
        return std::abs(underlying_price_at_expiry - strike);
    }
}

float Monte_Carlo_Vanilla_European(const int& number_of_simulations, const int& time_steps_per_simulation, const float& strike, const float& risk_free_interest_rate, const float& time_until_option_expiry, const float& volatility, const float& spot_price_of_underlying, float (*payoff_function)(const float strike, const float underlying_price_at_expiry)) {

    // Create new array on the heap.
    std::vector<float> array(number_of_simulations);

    float sum_payoff = 0;
    float discount_factor = std::exp(-risk_free_interest_rate * time_until_option_expiry);

    for (int i = 0; i < number_of_simulations; i++) {
        Geometric_Brownian_Motion(array, time_steps_per_simulation, spot_price_of_underlying, time_until_option_expiry, risk_free_interest_rate, volatility);
        sum_payoff += (*payoff_function)(strike, array[time_steps_per_simulation - 1]) * discount_factor;
    }

    return sum_payoff / number_of_simulations;
}
