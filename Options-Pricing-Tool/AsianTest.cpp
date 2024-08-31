#include "../Options-Pricing-Library/Asian.hpp"
#include "Constants.h"
#include "gtest/gtest.h"


TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Put) {
    const std::vector<float> vec = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Put(10, vec), 6.44444444, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Call) {
    const std::vector<float> vec = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Call(1, vec), 2.5555555555556, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Arithmetic_Chooser) {
    const std::vector<float> vec = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Chooser(1, vec), 2.5555555555556, tolerance);
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Arithmetic_Chooser(10, vec), 6.44444444, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Chooser) {
    const std::vector<float> vec = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Chooser(1, vec), 1.7976849784659, tolerance);
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Chooser(10, vec), 7.20231502, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Call) {
    const std::vector<float> vec = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Call(1, vec), 1.7976849784659, tolerance);
}

TEST(Payoff, Asian_Fixed_Strike_Geometric_Put) {
    const std::vector<float> vec = { 5, 4, 1, 7, 1, 3, 5, 1, 5 };
    EXPECT_NEAR(Payoff::Asian_Fixed_Strike_Geometric_Put(10, vec), 7.20231502, tolerance);
}
