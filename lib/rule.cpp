#include <rule.hpp>
#include <chess.hpp>
#include <cstdlib>

Rule::Rule(Board *board) : board(board) {}

BigBoardRule::BigBoardRule(Board *board) : Rule(board) {}

Rule::RuleReturnType BigBoardRule::validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) {
    // TODO:
    return RuleReturnType::VALID_MOVE;
}
Rule::RuleReturnType BigBoardRule::validateResult() {
    // TODO:
    return RuleReturnType::RED_WIN;
}

SmallBoardRule::SmallBoardRule(Board *board) : Rule(board) {}

Rule::RuleReturnType SmallBoardRule::validateMove(Chess &chess, unsigned nextRow, unsigned nextCol) {
    using ChessID = Chess::ChessID;

    // Check the boundary of board and if it's covered
    if(nextRow < 0 || nextRow >= board->rows || nextCol < 0 || nextCol >= board->cols || chess.folded) {
        return RuleReturnType::INVALID;
    }
    // Check the next position is near
    if(std::abs((int)nextRow-(int)chess.row) + std::abs((int)nextCol-(int)chess.col) != 1 && chess.id != ChessID::CANNON) {
        return RuleReturnType::INVALID;
    }
    if(!board->contains({nextRow, nextCol})) {
        return RuleReturnType::VALID_MOVE;
    }else {
         // Has another chess
        Chess nextChess = board->at({nextRow, nextCol});
        if(nextChess.color == chess.color) {
            return RuleReturnType::INVALID;
        }
        if(chess.id == ChessID::CANNON) {
            // Check if next position is in the same row / col
            if(nextRow != chess.row && nextCol != chess.col) {
                return RuleReturnType::INVALID;
            }
            unsigned minRow = std::min(nextRow, chess.row), minCol = std::min(nextCol, chess.col);
            unsigned maxRow = std::max(nextRow, chess.row), maxCol = std::max(nextCol, chess.col);
            unsigned cnt = 0; 
            for(unsigned i=minRow+1; i<=maxRow-1; i++) {
                cnt += (board->contains({i, chess.col}));
            }
            for(unsigned j=minCol+1; j<=maxCol-1; j++) {
                cnt += (board->contains({chess.row, j}));
            }
            return (cnt == 1) ? RuleReturnType::VALID_EAT : RuleReturnType::INVALID;
        }else if(chess.id == ChessID::SOLDIER) {
            return (nextChess.id == ChessID::KING) ? RuleReturnType::VALID_EAT : RuleReturnType::INVALID;
        }else if(chess.id == ChessID::KING) {
            return (nextChess.id != ChessID::SOLDIER) ? RuleReturnType::VALID_EAT : RuleReturnType::INVALID;
        }else {
            return (chess.id >= nextChess.id) ? RuleReturnType::VALID_EAT : RuleReturnType::INVALID;
        }
    }
}

Rule::RuleReturnType SmallBoardRule::validateUnfold(Chess &chess) {
    if(chess.folded == false) {
        return RuleReturnType::INVALID;
    }
    return RuleReturnType::VALID_UNFOLD;
}

Rule::RuleReturnType SmallBoardRule::validateResult() {
    unsigned blackN = 0, redN = 0;
    for(const auto& [_, chess] : *board) {
        if(chess.color == Chess::ChessColor::BLACK) {
            blackN += 1;
        }else {
            redN += 1;
        }
    }
    if(redN == 0) {
        return RuleReturnType::BLACK_WIN;
    }else if(blackN == 0) {
        return RuleReturnType::RED_WIN;
    }else {
        return RuleReturnType::CONTINUE;
    }
}