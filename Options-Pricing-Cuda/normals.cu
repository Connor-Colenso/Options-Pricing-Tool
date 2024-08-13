#include "normals.cuh"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <vector>
#include <stdio.h>
#include <curand.h>
#include <cmath>
#include <thrust/device_vector.h>
#include <iostream>

static curandGenerator_t curandGenerator = nullptr;


static void initRandGen() {
	curandCreateGenerator(&curandGenerator, CURAND_RNG_PSEUDO_MTGP32);
	curandSetPseudoRandomGeneratorSeed(curandGenerator, 1234ULL);
}


[[nodiscard]] std::vector<float> cudaNormals(const int steps) {

	if (curandGenerator == nullptr) initRandGen();

	const float dt = 1.0f / float(steps);

	float* gpuPtr;
	cudaMalloc(&gpuPtr, steps * sizeof(float));

	curandGenerateNormal(curandGenerator, gpuPtr, steps, 0.0f, 1.0f);
	thrust::device_ptr<float> gpu_vec(gpuPtr);

	std::vector<float> output_vec(steps);

	cudaMemcpy(output_vec.data(), gpuPtr, steps * sizeof(float), cudaMemcpyDeviceToHost);

	cudaFree(gpuPtr);

	return output_vec;
}