#pragma once
#include <vector>
#include <functional>
#include <future>
#include <thread>

float Monte_Carlo(const int number_of_simulations, const int time_steps_per_simulation, const float& strike, const float risk_free_interest_rate, const float& continuous_dividend_yield, const float time_until_option_expiry, const float volatility, const float spot_price_of_underlying, float (*payoff_function)(const float& strike, const std::vector<float>& array));
