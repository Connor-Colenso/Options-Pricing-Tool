#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <random>

std::minstd_rand gen_0(std::random_device{}());
std::normal_distribution<> d_0{ 0, 1 };

void Brownian_Motion_0(std::vector<float>& array, const int& n) {
	// Sample random values from a standardised normal distribution.

	std::minstd_rand gen(std::random_device{}());
	std::normal_distribution<> d{ 0, 1 };

	float tmp = 0.0f;
	float dt = (float)std::sqrt(1.0 / (float)(n));

	for (int i = 0; i < (n); ++i) {
		array[i] = tmp;
		tmp += float(d(gen)) * dt;
	}
}

void Brownian_Motion_1(std::vector<float>& array, const int& n) {
	// Sample random values from a standardised normal distribution.

	float tmp = 0.0f;
	float dt = (float)std::sqrt(1.0 / (float)(n));

	for (int i = 0; i < (n); ++i) {
		array[i] = tmp;
		tmp += float(d_0(gen_0)) * dt;
	}
}

int main() {
	// Monte Carlo Settings.
	constexpr int time_steps_per_simulation = 1000;
	constexpr int number_of_simulations = 50000000;

	// Option Settings.
	constexpr float strike = 15.0f;
	constexpr float risk_free_interest_rate = 0.05f;
	constexpr float continuous_dividend_yield = 0.01f;
	constexpr float time_until_option_expiry = 1.0f;
	constexpr float volatility = 0.04f;
	constexpr float spot_price_of_underlying = 14.5f;

	std::vector<float> v_1(number_of_simulations);

	auto time_1 = std::chrono::high_resolution_clock::now();

	//std::cout << Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Call) << std::endl;

	Brownian_Motion_1(v_1, v_1.size());
	
	auto time_2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms_double = time_2 - time_1;
	std::cout << ms_double.count() << "ms" << std::endl;
}
