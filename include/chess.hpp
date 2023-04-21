#ifndef CHESS_GUARD
#define CHESS_GUARD

class Chess {
        enum class ChessColor {RED = 0, BLACK = 1};
        enum class ChessID {SOLDIER = 0, CANNON, HOURSE, CAR, ELEPHANT, GUARD, KING};
    public:
        Chess(unsigned row, unsigned col, ChessColor color, ChessID id);
        void move(unsigned nextRow, unsigned nextCol);
        unsigned row, col;
        ChessColor color;
        ChessID id;
};

#endif