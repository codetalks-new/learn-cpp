#!/bin/bash
set -ux
c++ -std=c++14 -I./ -lgtest -lgmock -o bin/demo "$1" && bin/demo