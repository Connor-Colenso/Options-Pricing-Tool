#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Asian.hpp"
#include "../Options-Pricing-Library/MonteCarlo.hpp"
#include "Constants.h"


// ---------------------- Arithmetic Asian Options Tests ----------------------

// --- Arithmetic Put Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Put), 0.2548593282699585, tolerance);
}

// --- Arithmetic Call Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Call), 0.056176088750362396, tolerance);
}

// --- Arithmetic Chooser Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Chooser), 0.31023803353309631, tolerance);
}

// ---------------------- Geometric Asian Options Tests ----------------------

// --- Geometric Put Option ---

TEST(Monte_Carlo_Geometric_Asian, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Put), 0.25601232051849365, tolerance);
}

// --- Geometric Call Option ---

TEST(Monte_Carlo_Geometric_Asian, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Call), 0.054743491113185883, tolerance);
}

// --- Geometric Chooser Option ---

TEST(Monte_Carlo_Geometric_Asian, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Chooser), 0.30963024497032166, tolerance);
}