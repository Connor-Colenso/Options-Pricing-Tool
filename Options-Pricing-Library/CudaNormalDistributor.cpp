#include "CudaNormalDistributor.h"
#include "../Options-Pricing-Cuda/normals.cuh"
#include <random>

namespace {
	// Create a random device and a random number generator
	static std::random_device rd;  // Obtain a random number from hardware
	static std::mt19937 gen(rd()); // Seed the generator with the random device

	// Define the distribution range


	[[nodiscard]] int randInt(const int min, const int max) {
		static std::uniform_int_distribution<> dis(min, max);
		// Generate and return the random number
		return dis(gen);
	}
}

namespace CudaNormalDistributor {

	// Assuming cudaNormals is a function that returns a std::vector<float>
	const static std::vector<float> normals = cudaNormals(100000000);

	std::span<const float> requestNormals(const size_t amountRequested) {


		// Assuming randInt is defined elsewhere
		int offset = randInt(0, normals.size() - amountRequested);
		return std::span<const float>(normals.data() + offset, amountRequested);
	}
}
