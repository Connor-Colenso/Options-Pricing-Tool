#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <thread>

namespace Utility {
	void Brownian_Motion(std::vector<float>& array, const int& n);
	void Geometric_Brownian_Motion(std::vector<float>& array, const int& n, const float& x0, const float& t, const float& mu, const float& sigma);
}

namespace Payoff {
	float European_Put(const float& strike, const std::vector<float>& array);
	float European_Call(const float& strike, const std::vector<float>& array);
	float European_Chooser(const float& strike, const std::vector<float>& array);
	float European_Lookback_Max_Call(const float& strike, const std::vector<float>& array);
	float European_Lookback_Min_Put(const float& strike, const std::vector<float>& array);
	float European_Call_Squared(const float& strike, const std::vector<float>& array);
	float European_Put_Squared(const float& strike, const std::vector<float>& array);

	float Asian_Fixed_Strike_Arithmetic_Put(const float& strike, const std::vector<float>& array);
	float Asian_Fixed_Strike_Arithmetic_Call(const float& strike, const std::vector<float>& array);
	float Asian_Fixed_Strike_Arithmetic_Chooser(const float& strike, const std::vector<float>& array);

	float Asian_Fixed_Strike_Geometric_Put(const float& strike, const std::vector<float>& array);
	float Asian_Fixed_Strike_Geometric_Call(const float& strike, const std::vector<float>& array);
	float Asian_Fixed_Strike_Geometric_Chooser(const float& strike, const std::vector<float>& array);
}

float Monte_Carlo(const int number_of_simulations, const int time_steps_per_simulation, const float& strike, const float risk_free_interest_rate, const float& continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array), int thread_override = -1);
