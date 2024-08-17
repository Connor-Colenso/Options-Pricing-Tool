#pragma once
#include <vector>
#include <atomic>
#include <mutex>

class CudaNormalDistributor
{
	const static size_t m_normalsToStock = 100000000;
	static size_t m_startIndex;
	static std::vector<float> m_internalNormals;
	static std::mutex m_requestNormalsMutex;
public:
	static std::vector<float> requestNormals(size_t amountRequested);
};
