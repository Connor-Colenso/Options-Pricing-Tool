#include "Options-Pricing-Lib.h"

namespace Utility {
    void Brownian_Motion(std::vector<float>& array, const int& n) {
        // Sample random values from a standardised normal distribution.
        std::random_device rd{};
        std::mt19937 gen{ rd() };
        std::normal_distribution<> d{ 0, 1 };

        float tmp = 0;
        float dt = (float) std::sqrt(1.0 / (float)(n));

        for (int i = 0; i < (n); ++i) {
            array[i] = tmp;
            tmp += d(gen) * dt;
        }
    }

    void Geometric_Brownian_Motion(std::vector<float>& array, const int& n, const float& x0, const float& t, const float& mu, const float& sigma) {

        Brownian_Motion(array, n);

        float t_counter = 0;
        float pre_t_division = t / (float)n;

        float pre_calc_drift = mu - 0.5 * sigma * sigma;

        for (int i = 0; i < n; ++i) {
            array[i] = x0 * std::exp(pre_calc_drift * t_counter + array[i] * sigma);
            t_counter += pre_t_division;
        }
    }
}