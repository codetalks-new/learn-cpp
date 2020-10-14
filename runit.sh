#!/bin/bash
set -ux
c++ -std=c++17 -I./ -lgtest -lgmock -o bin/demo "$1" && bin/demo
