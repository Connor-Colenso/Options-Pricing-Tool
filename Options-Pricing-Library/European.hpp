#pragma once
#include <vector>
#include <algorithm>

namespace Payoff {
	float European_Put(const float& strike, const std::vector<float>& vec);
	float European_Call(const float& strike, const std::vector<float>& vec);
	float European_Chooser(const float& strike, const std::vector<float>& vec);
	float European_Call_Squared(const float& strike, const std::vector<float>& vec);
	float European_Put_Squared(const float& strike, const std::vector<float>& vec);
}