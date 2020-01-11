#!/bin/bash
set -ux
c++ -std=c++17 -lgtest -lgmock -o bin/demo "$1" && bin/demo