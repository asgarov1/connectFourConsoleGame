cmake_minimum_required(VERSION 3.16)
project(vierGewinnt)

set(CMAKE_CXX_STANDARD 17)

add_executable(vierGewinnt main.cpp Board.cpp Board.h Bot/RandomBot.cpp Bot/RandomBot.h Bot/IBot.h Bot/FromLeftBot.cpp Bot/FromLeftBot.h Game.cpp Game.h)