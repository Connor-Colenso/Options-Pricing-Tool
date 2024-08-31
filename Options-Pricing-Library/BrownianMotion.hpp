#pragma once
#include <functional>
#include <vector>

namespace Utility {
	void Brownian_Motion(std::vector<float>& vec);
	void Geometric_Brownian_Motion(std::vector<float>& brownian_motion_vec, const float& x0, const float& t, const float& mu, const float& sigma, const float& pre_t_division, const float& pre_calc_drift);
}
