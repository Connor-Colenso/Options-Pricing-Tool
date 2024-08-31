#include "gtest/gtest.h"
#include "../Options-Pricing-Library/European.hpp"
#include "Constants.h"


TEST(Payoff, European_Chooser) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::EuropeanChooser(10, v_0), 5);
    EXPECT_EQ(Payoff::EuropeanChooser(5, v_1), 5);
}

TEST(Payoff, European_Call) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::EuropeanCall(10, v_0), 0);
    EXPECT_EQ(Payoff::EuropeanCall(5, v_1), 5);
}

TEST(Payoff, European_Put) {
    const std::vector<float> v_0 = { 6,4,1,5 };
    const std::vector<float> v_1 = { 1,2,3,10 };

    EXPECT_EQ(Payoff::EuropeanPut(10, v_0), 5);
    EXPECT_EQ(Payoff::EuropeanPut(5, v_1), 0);
}

//TEST(Payoff, European_Call_Squared) {
//    const std::vector<float> v_0 = { 6,4,1,5 };
//    const std::vector<float> v_1 = { 1,2,3,10 };
//
//    EXPECT_EQ(Payoff::EuropeanCallPower<2.0f>(10, v_0), 0);
//    EXPECT_EQ(Payoff::EuropeanCallPower<2.0f>(5, v_1), 25);
//}


template <std::size_t N>
constexpr void testEuropeanPutPower(const float strike, const std::vector<float>& v_0, const std::vector<float>& answerVector) {

    if constexpr (N < 5) {
        EXPECT_NEAR(Payoff::EuropeanPutPower<N>(strike, v_0), answerVector[N], tolerance);
        testEuropeanPutPower<N + 1>(strike, v_0, answerVector);
    }
}

TEST(Payoff, European_Put_Squared) {
    const std::vector<float> v0 = { 6,4,1,5 };
    const std::vector<float> v1 = { 1,2,3,1 };

    const std::vector<float> answerVector0 = { 1, 5, 25, 125, 625 };
    const std::vector<float> answerVector1 = { 1, 0.5, 0.25, 0.125, 0.0625 };

    const float strike0 = 10;
    const float strike1 = 1.5;

    testEuropeanPutPower<0>(strike0, v0, answerVector0);
    testEuropeanPutPower<0>(strike1, v1, answerVector1);
}


template <std::size_t N>
constexpr void testEuropeanCallPower(const float strike, const std::vector<float>& v_0, const std::vector<float>& answerVector) {

    if constexpr (N < 5) {
        EXPECT_NEAR(Payoff::EuropeanCallPower<N>(strike, v_0), answerVector[N], tolerance);
        testEuropeanCallPower<N + 1>(strike, v_0, answerVector);
    }
}

TEST(Payoff, European_Call_Squared) {
    const std::vector<float> v0 = { 6,4,1,15 };
    const std::vector<float> v1 = { 1,2,3,11.3 };

    const std::vector<float> answerVector0 = { 1, 5, 25, 125, 625 };
    const std::vector<float> answerVector1 = { 1, 9.800000191, 96.04000092, 941.1920166, 9223.681641 };

    const float strike0 = 10;
    const float strike1 = 1.5;

    testEuropeanCallPower<0>(strike0, v0, answerVector0);
    testEuropeanCallPower<0>(strike1, v1, answerVector1);
}


//template <std::size_t N>
//constexpr void testEuropeanCallPower(const std::vector<float>& v_0, const std::vector<float>& v_1) {
//    if constexpr (N < 25) {
//        EXPECT_EQ(Payoff::EuropeanCallPower<N>(10, v_0), 25);
//        EXPECT_EQ(Payoff::EuropeanCallPower<N>(5, v_1), 0);
//        testEuropeanCallPower<N + 1>(v_0, v_1);
//    }
//}
//
//TEST(Payoff, European_Call_Squared) {
//    const std::vector<float> v_0 = { 6,4,1,5 };
//    const std::vector<float> v_1 = { 1,2,3,10 };
//
//    testEuropeanCallPower<0>(v_0, v_1);
//}
