cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c display.c display.h choosing.c choosing.h signing.h signing.c food.h food.c foodtype.c foodtype.h drink.h drink.c)