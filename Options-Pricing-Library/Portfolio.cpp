#include "Portfolio.hpp"

void Portfolio::addAsset(const std::shared_ptr<Asset> asset) {
	m_assetVector.push_back(asset);
}

[[nodiscard]] std::expected<Price, PriceError> Portfolio::getPrice(const boost::posix_time::ptime& ptime) const {
	
	Price totalPrice;
	
	for(const auto& asset : m_assetVector) {
		std::expected<Price, PriceError> price = asset->getPrice(ptime);
	
		if (price.has_value()) {
			totalPrice += price.value();
		}
	}

	return totalPrice;
}
