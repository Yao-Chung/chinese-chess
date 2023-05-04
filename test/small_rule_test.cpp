#include <gtest/gtest.h>
#include <vector>
#include <board.hpp>
#include <rule.hpp>
#include <chess.hpp>

class SmallGameRuleTest : public ::testing::Test {
  public:
    SmallGameRuleTest() : mockBoard(4, 8), smallRule(&mockBoard) {}

  protected:
    Board mockBoard;
    SmallBoardRule smallRule;

    void SetUp() override {
      // place chess on board, operator of map doesn't work
      mockBoard.insert({{0, 1}, Chess(0, 1, Chess::ChessColor::BLACK, Chess::ChessID::KING, false)});
      mockBoard.insert({{1, 1}, Chess(1, 1, Chess::ChessColor::RED, Chess::ChessID::SOLDIER, false)});
      mockBoard.insert({{2, 1}, Chess(2, 1, Chess::ChessColor::BLACK, Chess::ChessID::GUARD, false)});
      mockBoard.insert({{3, 1}, Chess(3, 1, Chess::ChessColor::RED, Chess::ChessID::KING, false)});
      mockBoard.insert({{2, 2}, Chess(2, 2, Chess::ChessColor::BLACK, Chess::ChessID::SOLDIER, false)});
      mockBoard.insert({{0, 4}, Chess(0, 4, Chess::ChessColor::BLACK, Chess::ChessID::ELEPHANT, true)});
      mockBoard.insert({{1, 5}, Chess(1, 5, Chess::ChessColor::BLACK, Chess::ChessID::HOURSE, false)});
      mockBoard.insert({{2, 4}, Chess(2, 4, Chess::ChessColor::BLACK, Chess::ChessID::KING, false)});
      mockBoard.insert({{2, 5}, Chess(2, 5, Chess::ChessColor::RED, Chess::ChessID::CANNON, false)});
      mockBoard.insert({{2, 6}, Chess(2, 6, Chess::ChessColor::RED, Chess::ChessID::SOLDIER, false)});
    }
    void TearDown() override {
      mockBoard.clear();
    }
};

// Move to outside
TEST_F(SmallGameRuleTest, boundaryCheck) {
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({3, 1}), 4, 1), Rule::RuleReturnType::INVALID);
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({2, 4}), 4, 4), Rule::RuleReturnType::INVALID);
}

// Move to diagonal position
TEST_F(SmallGameRuleTest, diagonalCheck) {
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({3, 1}), 2, 2), Rule::RuleReturnType::INVALID);
}

// Move folded chess
TEST_F(SmallGameRuleTest, foldedChessCheck) {
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({0, 4}), 0, 3), Rule::RuleReturnType::INVALID);
}

// Move to empty space
TEST_F(SmallGameRuleTest, moveToEmptyCheck) {
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({1, 1}), 1, 2), Rule::RuleReturnType::VALID_MOVE);
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({1, 5}), 1, 6), Rule::RuleReturnType::VALID_MOVE);
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({2, 2}), 2, 3), Rule::RuleReturnType::VALID_MOVE);
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({2, 6}), 2, 7), Rule::RuleReturnType::VALID_MOVE);
  ASSERT_EQ(smallRule.validateMove(mockBoard.at({3, 1}), 3, 2), Rule::RuleReturnType::VALID_MOVE);
}

// Eat enemy
TEST_F(SmallGameRuleTest, eatEnemyCheck) {
  ASSERT_EQ(1, 1);
}

// TEST_F(SmallGameRuleTest, printArrVal) {
  // EXPECT_EQ(arr[0], 10);
// }