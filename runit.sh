#!/bin/bash
set -ux
c++ -std=c++11 -lgtest -lgmock -o bin/demo "$1" && bin/demo