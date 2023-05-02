#include <cstdlib>
#include <chess.hpp>

Chess::Chess(unsigned row, unsigned col, ChessColor color, ChessID id, bool covered) : row(row), col(col), color(color), id(id), covered(covered){}

void Chess::move(unsigned nextRow, unsigned nextCol) {
    row = nextRow;
    col = nextCol;
}

void Chess::unfold() {
    covered = false;
}
