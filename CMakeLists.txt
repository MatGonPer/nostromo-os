cmake_minimum_required(VERSION 4.1.1)

project(NostromoOS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(NostromoOS src/main.cpp)

target_link_libraries(NostromoOS PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)