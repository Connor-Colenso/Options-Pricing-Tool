#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Utility.hpp"


TEST(Average, Geometric) {
	const std::vector<float> array = { 1,2,3,4,5,6,7 };
	EXPECT_NEAR(Geometric_Average(array), 3.380015159141, 10e-6);
}

TEST(Average, Arithmetic) {
	const std::vector<float> array = { 1,2,3,4,5,6,7 };
	EXPECT_NEAR(Arithmetic_Average(array), 4.0, 10e-6);
}
