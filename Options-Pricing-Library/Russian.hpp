#pragma once
#include <numeric>
#include <vector>

namespace Payoff {
	float Lookback_Max_Call(const float& strike, const std::vector<float>& vec);
	float Lookback_Min_Put(const float& strike, const std::vector<float>& vec);
}
