#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <random>
#include "../Options-Pricing-Library/AdvBinomial.hpp"

int main() {
	const float volatility = 0.05;
	const float risk_free_interest_rate = 0.05;
	const float strike = 5;
	const float spot_price = 5;
	const float time_period = 1;
	const float steps = 5;

	std::cout << Binomial(volatility, risk_free_interest_rate, strike, spot_price, time_period, steps);

}
