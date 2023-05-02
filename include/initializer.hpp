#ifndef INITIALIZER_GUARD
#define INITIALIZER_GUARD

#include <board.hpp>

class BaseInitializer {
    public:
        enum class InitReturnType {PASS = 0, INVALID = 1};
        virtual InitReturnType init(Board &board) = 0;
};

class BigBoardInitializer : public BaseInitializer {
    public:
        InitReturnType init(Board &board) override;
};

class SmallBoardInitializer : public BaseInitializer {
    public:
        InitReturnType init(Board &board) override;
};

#endif