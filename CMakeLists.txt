cmake_minimum_required(VERSION 3.22)

project(chiness_chess)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_subdirectory(lib)

include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/b796f7d.zip
)
FetchContent_MakeAvailable(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
enable_testing()
add_subdirectory(test)

set(SFML_FLAG ON CACHE BOOL "control SFML GUI option")
add_subdirectory(exec)
if(${SFML_FLAG})
  FetchContent_Declare(SFML
      GIT_REPOSITORY https://github.com/SFML/SFML.git
      GIT_TAG 2.6.x)
  FetchContent_MakeAvailable(SFML)
endif()
