#!/bin/bash

# Compile AVLTest.cpp
g++ AVLTest.cpp -Wall -Werror -std=c++11 -g -o AVLTest

# Run the compiled program through Valgrind
valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./AVLTest
./AVLTest


