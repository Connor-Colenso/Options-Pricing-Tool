#pragma once
#include <vector>


namespace Payoff {
	float Asian_Fixed_Strike_Arithmetic_Put(const float& strike, const std::vector<float>& vec);
	float Asian_Fixed_Strike_Arithmetic_Call(const float& strike, const std::vector<float>& vec);
	float Asian_Fixed_Strike_Arithmetic_Chooser(const float& strike, const std::vector<float>& vec);
	float Asian_Fixed_Strike_Geometric_Put(const float& strike, const std::vector<float>& vec);
	float Asian_Fixed_Strike_Geometric_Call(const float& strike, const std::vector<float>& vec);
	float Asian_Fixed_Strike_Geometric_Chooser(const float& strike, const std::vector<float>& vec);
}