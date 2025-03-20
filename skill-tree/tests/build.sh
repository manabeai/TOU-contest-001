#!/bin/bash

g++ -std=c++23 -O2 -Wall -Wextra -fsplit-stack judge.cpp -o checker
chmod 755 checker
