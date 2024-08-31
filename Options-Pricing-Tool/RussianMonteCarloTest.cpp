#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Russian.hpp"
#include "../Options-Pricing-Library/MonteCarlo.hpp"
#include "Constants.h"


// --- Lookback Max Option ---

TEST(Monte_Carlo_European, Lookback_Max_Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Lookback_Max_Call), 0.37840631604194641, tolerance * 3);
}        

// --- Lookback Min Option ---

TEST(Monte_Carlo_European, Lookback_Min_Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Lookback_Min_Put), 0.70214629173278809, tolerance * 3);
}
