#ifndef RULE_GUARD
#define RULE_GUARD

#include <chess.hpp>
#include <board.hpp>
class Rule {
    protected:
        Board *board;
    public:
        Rule(Board *board);
        enum class RuleReturnType {VALID = 0, INVALID, WIN, LOSE};
        virtual RuleReturnType validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) = 0;
};

class BigBoardRule : public Rule {
    public:
        BigBoardRule(Board *board);
        RuleReturnType validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) override;
};

class SmallBoardRule : public Rule {
    public:
        SmallBoardRule(Board *board);
        RuleReturnType validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) override;
        RuleReturnType validateUnfold(Chess &chess);
};

#endif