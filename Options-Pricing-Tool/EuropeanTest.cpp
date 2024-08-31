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

constexpr size_t powStart = 2;
constexpr size_t powEnd = 6;

template <const std::size_t start, const std::size_t end>
constexpr void testEuropeanPutPower(const float strike, const std::vector<float>& vec, const std::vector<float>& answerVector) {

    if constexpr (start < end) {
        EXPECT_NEAR(Payoff::EuropeanPutPower<start>(strike, vec), answerVector[start-powStart], tolerance);
        testEuropeanPutPower<start + 1, end>(strike, vec, answerVector);
    }
}

TEST(Payoff, European_Put_Squared) {
    const std::vector<float> fakePath0 = { 6,4,1,5 };
    const std::vector<float> fakePath1 = { 1,2,3,1 };

    const std::vector<float> answerVector0 = { 25, 125, 625, 3125 };
    const std::vector<float> answerVector1 = { 0.25, 0.125, 0.0625, 0.03125 };

    constexpr float strike0 = 10;
    constexpr float strike1 = 1.5;

    // Unique case to cross confirm that EuropeanPut = EuropeanPutPower<1>.
    EXPECT_NEAR(Payoff::EuropeanPutPower<1>(strike0, fakePath0), Payoff::EuropeanPut(strike0, fakePath0), tolerance);
    EXPECT_NEAR(Payoff::EuropeanPutPower<1>(strike1, fakePath1), Payoff::EuropeanPut(strike1, fakePath1), tolerance);

    // Now we test powers of powStart -> powEnd.
    testEuropeanPutPower<powStart, powEnd>(strike0, fakePath0, answerVector0);
    testEuropeanPutPower<powStart, powEnd>(strike1, fakePath1, answerVector1);
}


template <const std::size_t start, const std::size_t end>
constexpr void testEuropeanCallPower(const float strike, const std::vector<float>& vec, const std::vector<float>& answerVector) {

    if constexpr (start < end) {
        EXPECT_NEAR(Payoff::EuropeanCallPower<start>(strike, vec), answerVector[start - powStart], tolerance);
        testEuropeanCallPower<start + 1, end>(strike, vec, answerVector);
    }
}

TEST(Payoff, European_Call_Squared) {
    const std::vector<float> fakePath0 = { 6,4,1,15 };
    const std::vector<float> fakePath1 = { 1,2,3,11.3 };

    const std::vector<float> answerVector0 = { 25, 125, 625, 3125 };
    const std::vector<float> answerVector1 = { 96.04000092, 941.1920166, 9223.681641, 90392.0818447 };

    constexpr float strike0 = 10;
    constexpr float strike1 = 1.5;

    // Unique case to cross confirm that EuropeanCall = EuropeanCallPower<1>.
    EXPECT_NEAR(Payoff::EuropeanCallPower<1>(strike0, fakePath0), Payoff::EuropeanCall(strike0, fakePath0), tolerance);
    EXPECT_NEAR(Payoff::EuropeanCallPower<1>(strike1, fakePath1), Payoff::EuropeanCall(strike1, fakePath1), tolerance);

    // Now we test powers of powStart -> powEnd.
    testEuropeanCallPower<powStart, powEnd>(strike0, fakePath0, answerVector0);
    testEuropeanCallPower<powStart, powEnd>(strike1, fakePath1, answerVector1);
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
