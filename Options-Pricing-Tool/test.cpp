#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Options-Pricing-Lib.h"
#include "../Options-Pricing-Library/Brownian_Motion.cpp"
#include "../Options-Pricing-Library/CudaNormalDistributor.cpp"
#include "../Options-Pricing-Library/Monte_Carlo.cpp"
#include "../Options-Pricing-Library/Payoff.cpp"

// ---------------------- General Test Setup --------------------------

// Monte Carlo Settings.
static constexpr int time_steps_per_simulation = 10000;
static constexpr int number_of_simulations = 50000;

// Option Settings.
static constexpr float strike = 15.0f;
static constexpr float risk_free_interest_rate = 0.05f;
static constexpr float continuous_dividend_yield = 0.01f;
static constexpr float time_until_option_expiry = 1.0f;
static constexpr float volatility = 0.04f;
static constexpr float spot_price_of_underlying = 14.5f;

// Test Settings
static constexpr float tolerance = 0.01f;

// ---------------------- European Options Tests ----------------------

// --- Put Option ---

TEST(Monte_Carlo_European, Put) {
	EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Put), 0.18738, tolerance);
}

TEST(Payoff, European_Put) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Put(10, v_0), 5);
    EXPECT_EQ(Payoff::European_Put(5, v_1), 0);
}

// --- Call Option ---

TEST(Monte_Carlo_European, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Call), 0.27466, tolerance);
}

TEST(Payoff, European_Call) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Call(10, v_0), 0);
    EXPECT_EQ(Payoff::European_Call(5, v_1), 5);
}

// --- Chooser Option ---

TEST(Monte_Carlo_European, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Chooser), 0.46611, tolerance);
}

TEST(Payoff, European_Chooser) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Chooser(10, v_0), 5);
    EXPECT_EQ(Payoff::European_Chooser(5, v_1), 5);
}

// --- Lookback Max Option (Also known as Russian) ---

TEST(Monte_Carlo_European, Lookback_Max_Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Lookback_Max_Call), 0.37840631604194641, tolerance * 3);
}

TEST(Payoff, European_Lookback_Max_Call) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Lookback_Max_Call(10, v_0), 0);
    EXPECT_EQ(Payoff::European_Lookback_Max_Call(5, v_1), 5);
}

// --- Lookback Min Option ---

TEST(Monte_Carlo_European, Lookback_Min_Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Lookback_Min_Put), 0.70214629173278809, tolerance * 3);
}

TEST(Payoff, European_Lookback_Min_Put) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 3,2,3,10 };

    EXPECT_EQ(Payoff::European_Lookback_Min_Put(10, v_0), 9);
    EXPECT_EQ(Payoff::European_Lookback_Min_Put(5, v_1), 3);
}

// --- Call Squared Option ---

TEST(Monte_Carlo_European, Call_Squared) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Call_Squared), 0.22547394037246704, tolerance);
}

TEST(Payoff, European_Call_Squared) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Call_Squared(10, v_0), 0);
    EXPECT_EQ(Payoff::European_Call_Squared(5, v_1), 25);
}

// --- Put Squared Option ---

TEST(Monte_Carlo_European, Put_Squared) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Put_Squared), 0.13113369047641754, tolerance);
}

TEST(Payoff, European_Put_Squared) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Put_Squared(10, v_0), 25);
    EXPECT_EQ(Payoff::European_Put_Squared(5, v_1), 0);
}


// ---------------------- Arithmetic Asian Options Tests ----------------------

// --- Arithmetic Put Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Put), 0.2548593282699585, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Put) {
    const std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Put(10, array), 6.44444444, tolerance);
}

// --- Arithmetic Call Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Call), 0.056176088750362396, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Call) {
    const std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Call(1, array), 2.5555555555556, tolerance);
}

// --- Arithmetic Chooser Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Chooser), 0.31023803353309631, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Chooser) {
    const std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Chooser(1, array), 2.5555555555556, tolerance);
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Chooser(10, array), 6.44444444, tolerance);
}

// ---------------------- Geometric Asian Options Tests ----------------------

// --- Geometric Put Option ---

TEST(Monte_Carlo_Geometric_Asian, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Put), 0.25601232051849365, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Put) {
    const std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Put(10, array), 7.20231502, tolerance);
}

// --- Geometric Call Option ---

TEST(Monte_Carlo_Geometric_Asian, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Call), 0.054743491113185883, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Call) {
    const std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Call(1, array), 1.7976849784659, tolerance);
}

// --- Geometric Chooser Option ---

TEST(Monte_Carlo_Geometric_Asian, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Chooser), 0.30963024497032166, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Chooser) {
    const std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Chooser(1, array), 1.7976849784659, tolerance);
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Chooser(10, array), 7.20231502, tolerance);
}

// ---------------------- Average Tests ----------------------

TEST(Average, Geometric) {
    const std::vector<float> array = { 1,2,3,4,5,6,7 };
	EXPECT_NEAR(Geometric_Average(array), 3.380015159141, 10e-6);
}

TEST(Average, Arithmetic) {
    const std::vector<float> array = { 1,2,3,4,5,6,7 };
	EXPECT_NEAR(Arithmetic_Average(array), 4.0, 10e-6);
}

