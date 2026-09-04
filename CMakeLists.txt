cmake_minimum_required(VERSION 4.0)
project("aonmodem" C)

set (CMAKE_C_STANDARD 99)

add_executable(${PROJECT_NAME} main.c modem.c)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror -O2 -municode)