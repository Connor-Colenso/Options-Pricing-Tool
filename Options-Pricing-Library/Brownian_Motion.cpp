#include "Options-Pricing-Lib.h"


namespace Utility {
    void Brownian_Motion(std::vector<float>& array) {
        // Sample random values from a standardised normal distribution.
        std::minstd_rand gen(std::random_device{}());
        std::normal_distribution<> d{ 0, 1 };

        float tmp = 0.0f;
        float dt = 1.0f / std::sqrtf(array.size());

        for (int i = 0; i < array.size(); ++i) {
            array[i] = tmp;
            tmp += float(d(gen)) * dt;
        }
    }

    void Geometric_Brownian_Motion(std::vector<float>& array, const float& x0, const float& t, const float& mu, const float& sigma, const float& pre_t_division, const float& pre_calc_drift) {

        Brownian_Motion(array);

        for (int i = 0; i < array.size(); i++) {
            array[i] = x0 * std::exp(pre_calc_drift * pre_t_division * i + array[i] * sigma);
        }
    }
}
