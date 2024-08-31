#include "European.hpp"

namespace Payoff {

    float European_Put(const float& strike, const std::vector<float>& array) {
        float payoff = strike - array.back();

        return (payoff <= 0) ? 0 : payoff;
    }

    float European_Call(const float& strike, const std::vector<float>& array) {
        float payoff = (array.back() - strike);

        return (payoff <= 0) ? 0 : payoff;
    }

    float European_Chooser(const float& strike, const std::vector<float>& array) {
        return std::abs(array.back() - strike);
    }

    float European_Call_Squared(const float& strike, const std::vector<float>& array) {
        float payoff = (array.back() - strike);

        return (payoff <= 0) ? 0 : payoff * payoff;
    }

    float European_Put_Squared(const float& strike, const std::vector<float>& array) {
        float payoff = (strike - array.back());

        return (payoff <= 0) ? 0 : payoff * payoff;
    }
}