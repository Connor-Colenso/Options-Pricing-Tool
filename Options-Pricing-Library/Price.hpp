#pragma once

enum Currency {
	USD,
	GBP,
	CAD
};


// Default USD.
class Price
{
	double value = 0;
	Currency currency = USD;

public:

	Currency getCurrency() const {
		return currency;
	}

	double getValue() const {
		return value;
	}

	void convertCurrency(const Currency& currency) {
		
	}

	Price operator+(const Price& price) {
		this->value += price.value;
		return *this;
	}

	Price operator+=(const Price& price) {
		this->value += price.value;
		return *this;
	}
};

