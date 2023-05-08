if(${SFML_FLAG})
    add_executable(chess_game
        run.cpp
    )
    target_link_libraries(chess_game
        PRIVATE sfml-graphics
        game_lib
    )
    target_compile_features(chess_game PRIVATE cxx_std_20)
endif()

# install(TARGETS chess_game)
