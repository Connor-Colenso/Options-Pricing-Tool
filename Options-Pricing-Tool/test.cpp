#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Options-Pricing-Lib.h"
#include "../Options-Pricing-Library/Brownian_Motion.cpp"
#include "../Options-Pricing-Library/Monte_Carlo.cpp"
#include "../Options-Pricing-Library/Payoff.cpp"

// ---------------------- General Test Setup --------------------------

// Monte Carlo Settings.
constexpr int time_steps_per_simulation = 50;
constexpr int number_of_simulations = 5000000;

// Option Settings.
constexpr float strike = 15.0f;
constexpr float risk_free_interest_rate = 0.05f;
constexpr float continuous_dividend_yield = 0.01f;
constexpr float time_until_option_expiry = 1.0f;
constexpr float volatility = 0.04f;
constexpr float spot_price_of_underlying = 14.5f;

// Test Settings
constexpr float tolerance = 0.01;

// ---------------------- European Options Tests ----------------------

// --- Put Option ---

TEST(Monte_Carlo_European, Put) {
	EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Put), 0.18738, tolerance);
}

TEST(Payoff, European_Put) {
    std::vector<float> v_0 = { 6,4,1,5 };
    std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Put(10, v_0), 5);
    EXPECT_EQ(Payoff::European_Put(5, v_1), 0);
}

// --- Call Option ---

TEST(Monte_Carlo_European, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Call), 0.27466, tolerance);
}

TEST(Payoff, European_Call) {
    std::vector<float> v_0 = { 6,4,1,5 };
    std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Call(10, v_0), 0);
    EXPECT_EQ(Payoff::European_Call(5, v_1), 5);
}

// --- Chooser Option ---

TEST(Monte_Carlo_European, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::European_Chooser), 0.46611, tolerance);
}

TEST(Payoff, European_Chooser) {
    std::vector<float> v_0 = { 6,4,1,5 };
    std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Chooser(10, v_0), 5);
    EXPECT_EQ(Payoff::European_Chooser(5, v_1), 5);
}

// ---------------------- Arithmetic Asian Options Tests ----------------------

// --- Arithmetic Put Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Put), 0.2548593282699585, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Put) {
    std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Put(10, array), 6.44444444, tolerance);
}

// --- Arithmetic Call Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Call), 0, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Call) {
    std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Call(1, array), 2.5555555555556, tolerance);
}

// --- Arithmetic Chooser Option ---

TEST(Monte_Carlo_Arithmetic_Asian, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Arithmetic_Chooser), 0.31023803353309631, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Chooser) {
    std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Chooser(1, array), 2.5555555555556, tolerance);
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Chooser(10, array), 6.44444444, tolerance);
}

// ---------------------- Geometric Asian Options Tests ----------------------

// --- Geometric Put Option ---

TEST(Monte_Carlo_Geometric_Asian, Put) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Put), 0.25601232051849365, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Put) {
    std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Put(10, array), 7.20231502, tolerance);
}

// --- Geometric Call Option ---

TEST(Monte_Carlo_Geometric_Asian, Call) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Call), 0, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Call) {
    std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Call(1, array), 1.7976849784659, tolerance);
}

// --- Geometric Chooser Option ---

TEST(Monte_Carlo_Geometric_Asian, Chooser) {
    EXPECT_NEAR(Monte_Carlo(number_of_simulations, time_steps_per_simulation, strike, risk_free_interest_rate, continuous_dividend_yield, time_until_option_expiry, volatility, spot_price_of_underlying, &Payoff::Asian_Fixed_Strike_Geometric_Chooser), 0.30963024497032166, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Chooser) {
    std::vector<float> array = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Chooser(1, array), 1.7976849784659, tolerance);
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Chooser(10, array), 7.20231502, tolerance);
}
