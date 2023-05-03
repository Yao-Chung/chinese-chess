#ifndef RULE_GUARD
#define RULE_GUARD

#include <chess.hpp>
#include <board.hpp>
class Rule {
    protected:
        Board *board;
    public:
        Rule(Board *board);
        enum class RuleReturnType {VALID_MOVE = 0, VALID_UNFOLD, VALID_EAT, INVALID, RED_WIN, BLACK_WIN, CONTINUE};
        virtual RuleReturnType validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) = 0;
        virtual RuleReturnType validateResult() = 0;
};

class BigBoardRule : public Rule {
    public:
        BigBoardRule(Board *board);
        RuleReturnType validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) override;
        RuleReturnType validateResult() override;
};

class SmallBoardRule : public Rule {
    public:
        SmallBoardRule(Board *board);
        RuleReturnType validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) override;
        RuleReturnType validateResult() override;
        RuleReturnType validateUnfold(Chess &chess);
};

#endif