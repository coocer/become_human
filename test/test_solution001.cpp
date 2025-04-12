#include <gtest/gtest.h>
#include "solution001.h"

class Solution001Test : public ::testing::Test {
protected:
    Solution001 solution;
};

TEST_F(Solution001Test, NormalCase) {
    std::vector<int> input = {1, 2, 3, 4};
    std::vector<int> expected = {24, 12, 8, 6};
    
    auto result = solution.productExceptSelf(input);
    EXPECT_EQ(result, expected);
}

TEST_F(Solution001Test, WithZero) {
    std::vector<int> input = {0, 1, 2, 3};
    std::vector<int> expected = {6, 0, 0, 0};
    
    auto result = solution.productExceptSelf(input);
    EXPECT_EQ(result, expected);
}

TEST_F(Solution001Test, MultipleZeros) {
    std::vector<int> input = {0, 0, 2, 3};
    std::vector<int> expected = {0, 0, 0, 0};
    
    auto result = solution.productExceptSelf(input);
    EXPECT_EQ(result, expected);
}

TEST_F(Solution001Test, MinimalCase) {
    std::vector<int> input = {1, 1};
    std::vector<int> expected = {1, 1};
    
    auto result = solution.productExceptSelf(input);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
