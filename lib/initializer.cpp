#include <initializer.hpp>

BaseInitializer::InitReturnType BigBoardInitializer::init(Board &board) {
    return InitReturnType::PASS;
}

BaseInitializer::InitReturnType SmallBoardInitializer::init(Board &board) {
    return InitReturnType::PASS;
}