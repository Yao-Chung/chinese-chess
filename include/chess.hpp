#ifndef CHESS_GUARD
#define CHESS_GUARD

class Chess {
    public:
        enum class ChessColor {RED = 0, BLACK = 1};
        enum class ChessID {SOLDIER = 0, CANNON, HOURSE, CAR, ELEPHANT, GUARD, KING};
        Chess(unsigned row, unsigned col, ChessColor color, ChessID id, bool covered);
        void move(unsigned nextRow, unsigned nextCol);
        void unfold();
        unsigned row, col;
        bool covered;
        ChessColor color;
        ChessID id;
};

#endif