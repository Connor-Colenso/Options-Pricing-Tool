#pragma once

#include <expected>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "PriceError.hpp"
#include "Price.hpp"

class Asset
{
public:
	[[nodiscard]] virtual std::expected<Price, PriceError> getPrice(const boost::posix_time::ptime& ptime) const = 0;
	[[nodiscard]] std::expected<Price, PriceError> getPrice(const boost::gregorian::date& date, const boost::posix_time::time_duration& time) const;
};

