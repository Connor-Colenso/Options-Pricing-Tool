#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

void Brownian_Motion(std::vector<float>& array, const int& n);
void Geometric_Brownian_Motion(std::vector<float>& array, const int& n, const float& x0, const float& t, const float& mu, const float& sigma);

namespace Payoff {
	float European_Put(const float strike, const float underlying_price_at_expiry);
	float European_Call(const float strike, const float underlying_price_at_expiry);
	float European_Chooser(const float strike, const float underlying_price_at_expiry);
}

float Monte_Carlo_Vanilla_European(const int& number_of_simulations, const int& time_steps_per_simulation, const float& strike, const float& risk_free_interest_rate, const float& time_until_option_expiry, const float& volatility, const float& spot_price_of_underlying, float (*payoff_function)(const float strike, const float underlying_price_at_expiry));
