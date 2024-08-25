#include "CudaNormalDistributor.h"
#include "../Options-Pricing-Cuda/normals.cuh"

size_t CudaNormalDistributor::m_startIndex = CudaNormalDistributor::m_normalsToStock;
std::vector<float> CudaNormalDistributor::m_internalNormals;
std::mutex CudaNormalDistributor::m_requestNormalsMutex; 

std::vector<float> CudaNormalDistributor::requestNormals(size_t amountRequested)
{
	auto lock = std::unique_lock<std::mutex>(m_requestNormalsMutex);

	if (m_startIndex + amountRequested > m_normalsToStock) {
		m_internalNormals = cudaNormals(m_normalsToStock);
		m_startIndex = 0;
	}

	std::vector<float> normalsOut(amountRequested); 
	std::copy(m_internalNormals.begin() + m_startIndex,
		m_internalNormals.begin() + m_startIndex + amountRequested,
		normalsOut.begin());
	m_startIndex += amountRequested;

	return normalsOut;
}
