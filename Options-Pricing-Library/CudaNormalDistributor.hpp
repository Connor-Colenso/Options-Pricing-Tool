#pragma once
#include <vector>
#include <atomic>
#include <mutex>
#include <span>
#include <array>

namespace CudaNormalDistributor
{
	std::span<const float> requestNormals(const size_t amountRequested);
};
