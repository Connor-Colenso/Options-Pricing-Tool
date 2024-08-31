#pragma once
#include <vector>
#include <algorithm>
#include <cmath>

namespace Payoff {
	float EuropeanPut(const float& strike, const std::vector<float>& vec);
	float EuropeanCall(const float& strike, const std::vector<float>& vec);
	float EuropeanChooser(const float& strike, const std::vector<float>& vec);

    template<const float t>
    float EuropeanCallPower(const float& strike, const std::vector<float>& array) {
        float payoff = (array.back() - strike);

        return (payoff <= 0) ? 0 : std::powf(payoff, t);
    }

    template<const float t>
    float EuropeanPutPower(const float& strike, const std::vector<float>& array) {
        float payoff = (strike - array.back());

        return (payoff <= 0) ? 0 : std::powf(payoff, t);
    }
}