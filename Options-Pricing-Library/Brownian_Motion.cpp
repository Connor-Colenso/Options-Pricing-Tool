#include "Options-Pricing-Lib.h"
#include "../Options-Pricing-Cuda/normals.cuh"
#include "CudaNormalDistributor.h"

namespace Utility {
    void Brownian_Motion(std::vector<float>& array) {

        std::span<const float> normals = CudaNormalDistributor::requestNormals(array.size());

        float tmp = 0.0f;
        float dt = 1.0f / std::sqrtf((float) array.size());

        for (int i = 0; i < array.size(); ++i) {
            array[i] = tmp;
            tmp += normals[i] * dt;
        }
    }

    //void Brownian_Motion(std::vector<float>& array) {
    //    // Sample random values from a standardised normal distribution.
    //    std::minstd_rand gen(std::random_device{}());
    //    std::normal_distribution<> d{ 0, 1 };

    //    float tmp = 0.0f;
    //    float dt = 1.0f / std::sqrtf(array.size());

    //    for (int i = 0; i < array.size(); ++i) {
    //        array[i] = tmp;
    //        tmp += float(d(gen)) * dt;
    //    }
    //}

    void Geometric_Brownian_Motion(std::vector<float>& brownian_motion_vec, const float& x0, const float& t, const float& mu, const float& sigma, const float& pre_t_division, const float& pre_calc_drift) {

        Brownian_Motion(brownian_motion_vec);

        const float pre_calc = pre_calc_drift * pre_t_division;

        for (size_t i = 0; i < brownian_motion_vec.size(); i++) {
            brownian_motion_vec[i] = x0 * std::expf(pre_calc * i + brownian_motion_vec[i] * sigma);
        }
    }
}
