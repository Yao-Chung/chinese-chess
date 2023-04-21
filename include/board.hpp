#ifndef BOARD_GUARD
#define BOARD_GUARD

#include <chess.hpp>
#include <vector>

class Board : public std::vector<Chess> {
    public:
        Board(unsigned width, unsigned height);
        unsigned width;
        unsigned height;
};

#endif