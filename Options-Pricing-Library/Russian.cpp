#include "Russian.hpp"


namespace Payoff {
    float Lookback_Max_Call(const float& strike, const std::vector<float>& array) {
        float payoff = (*std::max_element(array.cbegin(), array.cend()) - strike);

        return (payoff <= 0) ? 0 : payoff;
    }

    float Lookback_Min_Put(const float& strike, const std::vector<float>& array) {
        float payoff = (strike - *std::min_element(array.cbegin(), array.cend()));

        return (payoff <= 0) ? 0 : payoff;
    }
}