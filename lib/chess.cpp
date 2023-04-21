#include <cstdlib>
#include <chess.hpp>

Chess::Chess(unsigned row, unsigned col, ChessColor color, ChessID id) : row(row), col(col), color(color), id(id) {}

void Chess::move(unsigned nextRow, unsigned nextCol) {
    this->row = nextRow;
    this->col = nextCol;
}