#ifndef BOARD_GUARD
#define BOARD_GUARD

#include <chess.hpp>
#include <map>
#include <utility>

class Board : public std::map<std::pair<unsigned, unsigned>, Chess> {
    public:
        unsigned rows;
        unsigned cols;
        Board(unsigned rows, unsigned cols);
        void remove(unsigned row, unsigned col);
};

#endif