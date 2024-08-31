#include "gtest/gtest.h"
#include "../Options-Pricing-Library/European.hpp"



TEST(Payoff, European_Chooser) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Chooser(10, v_0), 5);
    EXPECT_EQ(Payoff::European_Chooser(5, v_1), 5);
}

TEST(Payoff, European_Call) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Call(10, v_0), 0);
    EXPECT_EQ(Payoff::European_Call(5, v_1), 5);
}

TEST(Payoff, European_Put) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Put(10, v_0), 5);
    EXPECT_EQ(Payoff::European_Put(5, v_1), 0);
}

TEST(Payoff, European_Call_Squared) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Call_Squared(10, v_0), 0);
    EXPECT_EQ(Payoff::European_Call_Squared(5, v_1), 25);
}

TEST(Payoff, European_Put_Squared) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::European_Put_Squared(10, v_0), 25);
    EXPECT_EQ(Payoff::European_Put_Squared(5, v_1), 0);
}
