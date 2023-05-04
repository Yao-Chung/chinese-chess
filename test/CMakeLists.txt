add_executable( unit_tests
  small_rule_test.cpp
)
target_link_libraries(unit_tests
  game_lib
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(unit_tests)