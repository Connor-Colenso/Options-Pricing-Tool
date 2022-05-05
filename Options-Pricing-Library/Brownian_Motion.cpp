#include "Options-Pricing-Lib.h"

std::minstd_rand gen(std::random_device{}());
std::normal_distribution<> d{ 0, 1 };

namespace Utility {
    void Brownian_Motion(std::vector<float>& array, const int& n) {
        // Sample random values from a standardised normal distribution.



        float tmp = 0.0f;
        float dt = (float) std::sqrt(1.0 / (float)(n));

        for (int i = 0; i < (n); ++i) {
            array[i] = tmp;
            tmp += float(d(gen)) * dt;
        }
    }

    void Geometric_Brownian_Motion(std::vector<float>& array, const int& n, const float& x0, const float& t, const float& mu, const float& sigma) {
		
        Brownian_Motion(array, n);

        float t_counter = 0.0f;
        float pre_t_division = t / (float)n;

        float pre_calc_drift = mu - float(0.5) * sigma * sigma;

        for (int i = 0; i < n; ++i) {
            array[i] = x0 * std::exp(pre_calc_drift * t_counter + array[i] * sigma);
            t_counter += pre_t_division;
        }
    }
}