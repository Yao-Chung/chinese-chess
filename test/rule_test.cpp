#include <gtest/gtest.h>
#include <board.hpp>
#include <iostream>
#include <vector>

class SmallGameRuleTest : public ::testing::Test {
  protected:
    Board mockBoard;
    
    void SetUp() override {
    }
    void TearDown() override {
    }
};

// TEST_F(SmallGameRuleTest, printArr) {
  // for(auto a: arr) {
  //   std::cout << a << std::endl;
  // }
  // EXPECT_EQ(arr.size(), 1);
// }

// TEST_F(SmallGameRuleTest, printArrVal) {
  // EXPECT_EQ(arr[0], 10);
// }

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  std::map<std::pair<int, int>, int> mp;
  mp[{1, 2}] =  3;
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
