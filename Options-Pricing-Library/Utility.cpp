#include "Utility.hpp"


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
