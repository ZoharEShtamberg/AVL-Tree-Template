#!/bin/bash

# Compile AVLTest.cpp
g++ AVLTest.cpp -g -o AVLTest

# Run the compiled program through Valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./AVLTest
./AVLTest


