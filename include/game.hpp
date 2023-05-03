#ifndef GAME_GUARD
#define GAME_GUARD

#include <board.hpp>
#include <rule.hpp>
#include <initializer.hpp>

class Game {
    protected:
        Board *board;
        Rule *rule;
        BaseInitializer *initializer;
};

class BigGame : public Game {

};

class SmallGame : public Game {
    
};

#endif