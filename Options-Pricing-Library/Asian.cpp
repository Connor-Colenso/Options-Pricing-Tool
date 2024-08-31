#include "Asian.hpp"
#include "Utility.h"


namespace Payoff {

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