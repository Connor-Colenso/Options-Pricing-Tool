#include "Options-Pricing-Lib.h"
#include <numeric>

namespace Payoff {

    // ----------------- European Payoffs ---------------------

    float European_Put(const float& strike, const std::vector<float>& array) {
        float payoff = strike - array[array.size() - 1];

        return (payoff <= 0) ? 0 : payoff;
    }

    float European_Call(const float& strike, const std::vector<float>& array) {
        float payoff = (array[array.size() - 1] - strike);

        return (payoff <= 0) ? 0 : payoff;
    }

    float European_Chooser(const float& strike, const std::vector<float>& array) {
        return std::abs(array[array.size() - 1] - strike);
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

float Arithmetic_Average(std::vector<float> array) {
    return std::accumulate(array.begin(), array.end(), 0.0) / (float)array.size();
}

float Geometric_Average(std::vector<float> array) {
    float total_prod = 1;
    float exponent = (float)array.size();

    for (const auto& i : array) {
        total_prod *= pow(i, 1.0 / exponent);
    }

    return total_prod;
}