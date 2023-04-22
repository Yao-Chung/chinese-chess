#ifndef RULE_GUARD
#define RULE_GUARD

#include <chess.hpp>

class Rule {
    public:
        using RuleReturnType = bool;
        virtual RuleReturnType validate(Chess chess, unsigned nextRow, unsigned nextCol) = 0;
};

class BigBoardRule : public Rule {
    public:
        RuleReturnType validate(Chess chess, unsigned nextRow, unsigned nextCol);
};

class SmallBoardRule : public Rule {
    public:
        RuleReturnType validate(Chess chess, unsigned nextRow, unsigned nextCol);
};

#endif