cmake_minimum_required(VERSION 3.29)
project(LayingGrass)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/dist)

add_executable(LayingGrass
        src/main.cpp
        src/Cell.cpp
        src/Player.cpp
        src/MoldTiles.cpp
        src/Game.cpp
        src/Board.cpp
        src/shapeTile.cpp
        src/shapeTile.h
        src/Art.cpp
        src/Color.cpp
        src/resource.rc
)

target_link_options(LayingGrass PUBLIC -static -static-libgcc -static-libstdc++)
