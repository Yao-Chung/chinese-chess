#include <cstdlib>
#include <chess.hpp>

Chess::Chess(unsigned row, unsigned col, ChessColor color, ChessID id, bool folded) : row(row), col(col), color(color), id(id), folded(folded){}

void Chess::move(unsigned nextRow, unsigned nextCol) {
    row = nextRow;
    col = nextCol;
}

void Chess::unfold() {
    folded = false;
}
