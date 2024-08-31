#include "gtest/gtest.h"
#include "../Options-Pricing-Library/European.hpp"
#include "../Options-Pricing-Library/MonteCarlo.hpp"
#include "Constants.h"

// ---------------------- European Options Tests ----------------------

// --- Put Option ---

TEST(Monte_Carlo_European, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Put), 0.18738, tolerance);
}

// --- Call Option ---

TEST(Monte_Carlo_European, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Call), 0.27466, tolerance);
}

// --- Chooser Option ---

TEST(Monte_Carlo_European, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Chooser), 0.46611, tolerance);
}

// --- Call Squared Option ---

TEST(Monte_Carlo_European, Call_Squared) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Call_Squared), 0.22547394037246704, tolerance);
}

// --- Put Squared Option ---

TEST(Monte_Carlo_European, Put_Squared) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Put_Squared), 0.13113369047641754, tolerance);
}
