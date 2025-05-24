#pragma once
#include <functional>

float Binomial(
    const float volatility,
    const float risk_free_rate,
    const float strike,
    const float spot_price,
    const float time_period,
    const int steps,
    const std::function<float(float, float)> payoff);