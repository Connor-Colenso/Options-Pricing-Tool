#include "European.hpp"

namespace Payoff {

    float EuropeanPut(const float& strike, const std::vector<float>& array) {
        float payoff = strike - array.back();

        return (payoff <= 0) ? 0 : payoff;
    }

    float EuropeanCall(const float& strike, const std::vector<float>& array) {
        float payoff = (array.back() - strike);

        return (payoff <= 0) ? 0 : payoff;
    }

    float EuropeanChooser(const float& strike, const std::vector<float>& array) {
        return std::abs(array.back() - strike);
    }
}