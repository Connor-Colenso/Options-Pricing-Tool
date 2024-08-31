#include "gtest/gtest.h"
#include "../Options-Pricing-Library/Russian.hpp"


TEST(Payoff, Lookback_Max_Call) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::Lookback_Max_Call(10, v_0), 0);
    EXPECT_EQ(Payoff::Lookback_Max_Call(5, v_1), 5);
}

TEST(Payoff, Lookback_Min_Put) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 3,2,3,10 };

    EXPECT_EQ(Payoff::Lookback_Min_Put(10, v_0), 9);
    EXPECT_EQ(Payoff::Lookback_Min_Put(5, v_1), 3);
}