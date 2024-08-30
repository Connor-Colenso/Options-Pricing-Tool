#include "Options-Pricing-Lib.h"
#include <numeric>

namespace Payoff {

    // ----------------- European Payoffs ---------------------

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

    float European_Put_Squared(const float& strike, const std::vector<float>& array) {
        float payoff = (strike - array.back());

        return (payoff <= 0) ? 0 : payoff * payoff;
    }

    float European_Call_Squared(const float& strike, const std::vector<float>& array) {
        float payoff = (array.back() - strike);

        return (payoff <= 0) ? 0 : payoff * payoff;
    }

    float European_Lookback_Max_Call(const float& strike, const std::vector<float>& array) {
        float payoff = (*std::max_element(array.cbegin(), array.cend()) - strike);

        return (payoff <= 0) ? 0 : payoff;
    }

    float European_Lookback_Min_Put(const float& strike, const std::vector<float>& array) {
        float payoff = (strike - *std::min_element(array.cbegin(), array.cend()));

        return (payoff <= 0) ? 0 : payoff;
    }

    // ----------------- Asian Payoffs ---------------------

    float Asian_Fixed_Strike_Arithmetic_Put(const float& strike, const std::vector<float>& array) {
        float avg = Arithmetic_Average(array);
        float payoff = strike - avg;
        
        return payoff <= 0 ? 0 : payoff;
    }

    float Asian_Fixed_Strike_Arithmetic_Call(const float& strike, const std::vector<float>& array) {
        float avg = Arithmetic_Average(array);
        float payoff = avg - strike;

        return payoff <= 0 ? 0 : payoff;
    }

    float Asian_Fixed_Strike_Arithmetic_Chooser(const float& strike, const std::vector<float>& array) {
        float avg = Arithmetic_Average(array);

        return std::abs(avg - strike);
    }

    float Asian_Fixed_Strike_Geometric_Put(const float& strike, const std::vector<float>& array) {
        float avg = Geometric_Average(array);
        float payoff = strike - avg;

        return payoff <= 0 ? 0 : payoff;
    }

    float Asian_Fixed_Strike_Geometric_Call(const float& strike, const std::vector<float>& array) {
        float avg = Geometric_Average(array);
        float payoff = avg - strike;

        return payoff <= 0 ? 0 : payoff;
    }

    float Asian_Fixed_Strike_Geometric_Chooser(const float& strike, const std::vector<float>& array) {
        float avg = Geometric_Average(array);

        return std::abs(avg - strike);
    }
}

float Arithmetic_Average(const std::vector<float>& array) {
    return std::accumulate(array.cbegin(), array.cend(), 0.0f) / (float)array.size();
}

float Geometric_Average(const std::vector<float>& array) {
    float log2fsum = std::transform_reduce(
        array.cbegin(), array.cend(),
        0.0f,
        std::plus<>(),
        [](const float val) { return std::log2f(val); }
    );

    float sum = log2fsum / static_cast<float>(array.size());

    return std::pow(2.0f, sum);
}