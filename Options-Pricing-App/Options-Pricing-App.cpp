#include <iostream>
#include "../Options-Pricing-Library/Options-Pricing-Lib.h"
#include "../Options-Pricing-Library/Brownian_Motion.cpp"
#include "../Options-Pricing-Library/Monte_Carlo.cpp"
#include "../Options-Pricing-Library/Payoff.cpp"

#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>

int main() {
	// Monte Carlo Settings.
	constexpr int time_steps_per_simulation = 1000;
	constexpr int number_of_simulations = 5000000;

	// Option Settings.
	constexpr float strike = 15.0f;
	constexpr float risk_free_interest_rate = 0.05f;
	constexpr float continuous_dividend_yield = 0.01f;
	constexpr float time_until_option_expiry = 1.0f;
	constexpr float volatility = 0.04f;
	constexpr float spot_price_of_underlying = 14.5f;

	auto time_1 = std::chrono::high_resolution_clock::now();

	//std::cout << Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Call) << std::endl;
	std::vector<float> array = { 1,2,3,4,5,6,1 };
	std::cout << Payoff::European_Lookback_Min_Put(4, array) << std::endl;

	auto time_2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms_double = time_2 - time_1;

	std::cout << ms_double.count() << "ms" << std::endl;
}
