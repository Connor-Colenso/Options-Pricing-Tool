// Monte Carlo Settings.
constexpr int time_steps_per_simulation = 10000;
constexpr int number_of_simulations = 50000;

// Option Settings.
constexpr float strike = 15.0f;
constexpr float risk_free_interest_rate = 0.05f;
constexpr float continuous_dividend_yield = 0.01f;
constexpr float time_until_option_expiry = 1.0f;
constexpr float volatility = 0.04f;
constexpr float spot_price_of_underlying = 14.5f;

// Test Settings
constexpr float tolerance = 0.01f;