#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Options-Pricing-Lib.h"
#include "../Options-Pricing-Library/Options-Pricing-Lib.cpp"

TEST(MonteCarloEuropean, Put) {
	constexpr int n = 1000; // Number of steps used in each simulation.
    constexpr int number_of_simulations = 100000; // Number of simulations.

    constexpr float k = 15; // Strike
    constexpr float r = 0.05; // Risk-free interest rate
    constexpr float t = 1; // Time until option expiry
    constexpr float sigma = 0.04; // Volatility
    constexpr float x0 = 14; // Spot price.

	EXPECT_NEAR(Monte_Carlo_Vanilla_European(number_of_simulations, n, k, r, t, sigma, x0, &Payoff::European_Put), 0.38471, 10e-2);
}

TEST(MonteCarloEuropean, Call) {
    constexpr int n = 1000; // Number of steps used in each simulation.
    constexpr int number_of_simulations = 100000; // Number of simulations.

    constexpr float k = 15; // Strike
    constexpr float r = 0.05; // Risk-free interest rate
    constexpr float t = 1; // Time until option expiry
    constexpr float sigma = 0.04; // Volatility
    constexpr float x0 = 14; // Spot price.

    EXPECT_NEAR(Monte_Carlo_Vanilla_European(number_of_simulations, n, k, r, t, sigma, x0, &Payoff::European_Call), 0.11627, 10e-2);
}

TEST(MonteCarloEuropean, Chooser) {
    constexpr int n = 1000; // Number of steps used in each simulation.
    constexpr int number_of_simulations = 100000; // Number of simulations.

    constexpr float k = 15; // Strike
    constexpr float r = 0.05; // Risk-free interest rate
    constexpr float t = 1; // Time until option expiry
    constexpr float sigma = 0.04; // Volatility
    constexpr float x0 = 14; // Spot price.

    EXPECT_NEAR(Monte_Carlo_Vanilla_European(number_of_simulations, n, k, r, t, sigma, x0, &Payoff::European_Chooser), 0.50190, 10e-2);
}
