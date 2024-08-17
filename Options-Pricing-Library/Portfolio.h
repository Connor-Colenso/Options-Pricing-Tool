#pragma once
#include "Asset.h"
#include <memory>
#include <vector>

class Portfolio : public Asset
{
	void addAsset(const std::shared_ptr<Asset> asset);
	[[nodiscard]] std::expected<Price, PriceError> getPrice(const boost::posix_time::ptime& ptime) const override;

private:
	std::vector<std::shared_ptr<Asset>> m_assetVector{};
	
};

