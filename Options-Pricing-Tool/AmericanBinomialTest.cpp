#include "gtest/gtest.h"
#include "../Options-Pricing-Library/AdvBinomial.hpp"
#include "../Options-Pricing-Library/American.hpp"

// Test Settings
constexpr float tolerance = 0.01f;
constexpr int steps = 50;

TEST(Binomial_American, Put0) {
	constexpr float volatility = 0.07f;
	constexpr float risk_free_interest_rate = 0.09f;
	constexpr float strike = 5;
	constexpr float spot_price = 5;
	constexpr float time_period = 1.5f;
	constexpr int steps = 100;

	const float put_val = Binomial(volatility, risk_free_interest_rate, strike, spot_price, time_period, steps, &put_payoff);
	EXPECT_NEAR(put_val, 0.05f, tolerance);
}

TEST(Binomial_American, Put1) {
	constexpr float volatility = 1.26f;
	constexpr float risk_free_interest_rate = 0.03f;
	constexpr float strike = 220;
	constexpr float spot_price = 170;
	constexpr float time_period = 0.9f;
	constexpr int steps = 500;

	const float put_val = Binomial(volatility, risk_free_interest_rate, strike, spot_price, time_period, steps, &put_payoff);
	EXPECT_NEAR(put_val, 110.92f, tolerance);
}

TEST(Binomial_American, Call0) {
	constexpr float volatility = 0.07f;
	constexpr float risk_free_interest_rate = 0.09f;
	constexpr float strike = 5;
	constexpr float spot_price = 5;
	constexpr float time_period = 1.5f;
	constexpr int steps = 100;

	const float call_val = Binomial(volatility, risk_free_interest_rate, strike, spot_price, time_period, steps, &call_payoff);
	EXPECT_NEAR(call_val, 0.64f, tolerance);
}

TEST(Binomial_American, Call1) {
	constexpr float volatility = 0.04f;
	constexpr float risk_free_interest_rate = 0.03f;
	constexpr float strike = 15;
	constexpr float spot_price = 17;
	constexpr float time_period = 1.3f;
	constexpr int steps = 100;

	const float call_val = Binomial(volatility, risk_free_interest_rate, strike, spot_price, time_period, steps, &call_payoff);
	EXPECT_NEAR(call_val, 2.57f, tolerance);
}
