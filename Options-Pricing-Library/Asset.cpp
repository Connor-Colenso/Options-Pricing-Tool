#include "Asset.h"


[[nodiscard]] std::expected<Price, PriceError> Asset::getPrice(const boost::gregorian::date& date, const boost::posix_time::time_duration& time) const {
	return getPrice(boost::posix_time::ptime{ date, time });
}
