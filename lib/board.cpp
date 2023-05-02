#include <board.hpp>

Board::Board(unsigned rows, unsigned cols) : rows(rows), cols(cols) {}

void Board::remove(unsigned row, unsigned col) {
    erase(std::make_pair(row, col));
}