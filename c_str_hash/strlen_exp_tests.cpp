#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "concurrent/stopwatch.hpp"
#include "strlen_exp.c"

using std::cout;
using std::endl;
using std::string;
/**
 *

 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}()?#!=^&@'
 */
const char strs[][257] = {
    "a",
    "ab",
    "abc",
    "abcd",
    "abcde",
    "abcdef",
    "abcdefg",
    "abcdefgh",
    "abcdefghi",
    "abcdefghij",
    "abcdefghijk",
    "abcdefghijkl",
    "abcdefghijklm",
    "abcdefghijklmn",
    "abcdefghijklmno",
    "abcdefghijklmnop",
    "abcdefghijklmnopq",
    "abcdefghijklmnopqr",
    "abcdefghijklmnopqrs",
    "abcdefghijklmnopqrst",
    "abcdefghijklmnopqrstu",
    "abcdefghijklmnopqrstuv",
    "abcdefghijklmnopqrstuvw",
    "abcdefghijklmnopqrstuvwx",
    "abcdefghijklmnopqrstuvwxy",
    "abcdefghijklmnopqrstuvwxyz",
    "abcdefghijklmnopqrstuvwxyzA",
    "abcdefghijklmnopqrstuvwxyzAB",
    "abcdefghijklmnopqrstuvwxyzABC",
    "abcdefghijklmnopqrstuvwxyzABCD",
    "abcdefghijklmnopqrstuvwxyzABCDE",
    "abcdefghijklmnopqrstuvwxyzABCDEF",
    "abcdefghijklmnopqrstuvwxyzABCDEFG",
    "abcdefghijklmnopqrstuvwxyzABCDEFGH",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHI",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKL",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNO",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQR",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRS",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVW",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345678",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}(",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@a",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@ab",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abc",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcd",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcde",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdef",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefg",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefgh",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghi",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghij",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijk",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijkl",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklm",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmn",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmno",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnop",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopq",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqr",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrs",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrst",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstu",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuv",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvw",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwx",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxy",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyz",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzA",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzAB",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABC",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCD",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDE",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEF",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFG",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGH",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHI",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJK",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKL",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNO",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQR",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRS",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVW",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345678",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}(",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@a",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@ab",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abc",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcd",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcde",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdef",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefg",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefgh",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghi",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghij",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijk",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijkl",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklm",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmn",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmno",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnop",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopq",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqr",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrs",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrst",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstu",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuv",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvw",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwx",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxy",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyz",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzA",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzAB",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABC",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCD",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDE",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEF",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFG",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGH",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHI",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJK",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKL",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNO",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQR",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRS",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVW",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345678",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}(",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@a",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@ab",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abc",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcd",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcde",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdef",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefg",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefgh",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghi",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghij",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijk",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijkl",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@"
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/"
    "%*[]{}()?#!=^&@abcdefghijklm"

};

TEST(StrlenTestSuite, NormalStrlen) {
  for (int i = 0; i < 256; i++) {
    int expected = i + 1;
    EXPECT_EQ(normal_strlen(strs[i]), expected);
  }
  StopWatch watch;
  watch.start();
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 256; i++) {
      normal_strlen(strs[i]);
    }
  }

  printf("normal_strlen ns:%ld\n", watch.get_ns());
}

TEST(StrlenTestSuite, GccStrlen) {
  for (int i = 0; i < 256; i++) {
    int expected = i + 1;
    EXPECT_EQ(gcc_strlen(strs[i]), expected);
  }
  StopWatch watch;
  watch.start();
  for (int j = 0; j < 1000; j++) {
    for (int i = 0; i < 256; i++) {
      gcc_strlen(strs[i]);
    }
  }

  printf("gcc_strlen ns:%ld\n", watch.get_ns());
}

TEST(StrlenTestSuite, Utf8Strlen) {
  char s1[] = "abc";
  EXPECT_EQ(utf8_strlen(s1), sizeof(s1) - 1);
  const char *s2 = "我爱我的小月儿";
  EXPECT_EQ(utf8_strlen(s2), 7);
  const char *s3 = "I Love 小月儿";
  EXPECT_EQ(utf8_strlen(s3), 1 + 1 + 4 + 1 + 3);

  const char *bad1 = "\xf4";
  EXPECT_EQ(utf8_strlen(bad1), -1);

  const char *bad2 = "\xe8\x8c\x04";
  EXPECT_EQ(utf8_strlen(bad2), -1);
}

inline void swap_char(char *str, unsigned i, unsigned j) {
  char tmp = str[i];
  str[i] = str[j];
  str[j] = tmp;
}

void reverse_nstr(char *str, unsigned start, unsigned end) {
  assert(str != NULL);
  for (int i = start, j = end; i < j; i++, j--) {
    swap_char(str, i, j);
  }
}

void reverse_str(char *str) {
  reverse_nstr(str, 0, strlen(str) - 1);
}

inline void skip_space_backward(char *str, int *i) {
  int j = *i;
  for (; str[j] == ' '; j--) {
  }
  *i = j;
}

inline unsigned skip_space(char **str) {
  char *s = *str;
  int cnt = 0;
  for (; *s == ' '; s++) {
    cnt++;
    ;
  }
  *str = s;
  return cnt;
}

void normalize_sentence(char *str) {
  char *s = str;
  char *d = str;
  bool has_trailing_space = false;
  int extra_space_cnt = 0;
  while (*s) {
    extra_space_cnt += skip_space(&s);
    has_trailing_space = !*s;
    if (extra_space_cnt) {
      for (; *s && *s != ' '; s++) {
        *d++ = *s;
      }
    } else {
      for (; *s && *s != ' '; s++, d++) {
      }
    }
    if (*s) {
      // 说明 *s == ' ' skip normal space
      *d++ = *s++;
      has_trailing_space = true;
    }
  }
  if (has_trailing_space && d != str) {
    *(d - 1) = '\0';
  } else {
    *d = '\0';
  }
}

void reverse_sentence(char *str) {
  if (str == NULL) {
    return;
  }
  normalize_sentence(str);
  const unsigned len = strlen(str);
  if (len < 2) {
    return;
  }

  int i = 0;
  while (i < len) {
    int k = 0;
    int j = i;
    for (; j < len && str[j] != ' '; j++) {
    }
    reverse_nstr(str, i, j - 1);
    i = j + 1;  // one for space
  }
  reverse_nstr(str, 0, len - 1);
}

void expect_basic_reverse(void (*reverse)(char *)) {
  char s0[] = "";
  reverse(s0);
  EXPECT_STREQ(s0, "");

  char s1[] = "a";
  reverse(s1);
  EXPECT_STREQ(s1, "a");

  char s2[] = "ab";
  reverse(s2);
  EXPECT_STREQ(s2, "ba");

  char s3[] = "abc";
  reverse(s3);
  EXPECT_STREQ(s3, "cba");

  char s4[] = "abcd";
  reverse(s4);
  EXPECT_STREQ(s4, "dcba");
}

TEST(StrReverseTips, Reverse) {
  expect_basic_reverse(reverse_str);
}

TEST(StrReverseTips, NormalizeSenence) {
  char s0[] = " ";
  normalize_sentence(s0);
  EXPECT_STREQ(s0, "");

  char s1[] = "a";
  normalize_sentence(s1);
  EXPECT_STREQ(s1, "a");

  char s2[] = " a ";
  normalize_sentence(s2);
  EXPECT_STREQ(s2, "a");

  char s3[] = " ab  c ";
  normalize_sentence(s3);
  EXPECT_STREQ(s3, "ab c");

  char s4[] = " ab  c";
  normalize_sentence(s4);
  EXPECT_STREQ(s4, "ab c");

  char s5[] = " ab  c";
  normalize_sentence(s5);
  EXPECT_STREQ(s5, "ab c");

  char s6[] = " ab  cde ";
  normalize_sentence(s6);
  EXPECT_STREQ(s6, "ab cde");

  char s7[] = " hello world!   ";
  normalize_sentence(s7);
  EXPECT_STREQ(s7, "hello world!");
}

TEST(StrReverseTips, ReverseSentence) {
  char s0[] = " ";
  reverse_sentence(s0);
  EXPECT_STREQ(s0, "");

  char s1[] = "a";
  reverse_sentence(s1);
  EXPECT_STREQ(s1, "a");

  char s2[] = "ab";
  reverse_sentence(s2);
  EXPECT_STREQ(s2, "ab");

  char s3[] = "abc";
  reverse_sentence(s3);
  EXPECT_STREQ(s3, "abc");

  char s4[] = "abcd";
  reverse_sentence(s4);
  EXPECT_STREQ(s4, "abcd");

  char s5[] = "ab cd";
  reverse_sentence(s5);
  EXPECT_STREQ(s5, "cd ab");

  char s6[] = "ab cde fg";
  reverse_sentence(s6);
  EXPECT_STREQ(s6, "fg cde ab");

  char s7[] = " I am  Who ";
  reverse_sentence(s7);
  EXPECT_STREQ(s7, "Who am I");

  char s8[] = " hello world! ";
  reverse_sentence(s8);
  EXPECT_STREQ(s8, "world! hello");
}

void str_shift(char *str, int n) {
  int len = strlen(str);
  if (len < 2) {
    return;
  }
  n = n % len;
  if (n == 0) {
    return;
  }
  n = n < 0 ? len + n : n;
  int left_len = len - n;
  reverse_nstr(str, 0, left_len - 1);
  reverse_nstr(str, left_len, len - 1);
  reverse_nstr(str, 0, len - 1);
}

TEST(StrReverseTips, ShiftRight) {
  char s0[] = "";
  str_shift(s0, 8);
  EXPECT_STREQ(s0, "");

  char s1[] = "a";
  str_shift(s1, 1);
  EXPECT_STREQ(s1, "a");
  str_shift(s1, 2);
  EXPECT_STREQ(s1, "a");
  str_shift(s1, -1);
  EXPECT_STREQ(s1, "a");

  char s2[] = "ab";
  str_shift(s2, 1);
  EXPECT_STREQ(s2, "ba");
  str_shift(s2, 2);
  EXPECT_STREQ(s2, "ba");

  char s3[] = "abc";
  str_shift(s3, 1);
  EXPECT_STREQ(s3, "cab");

  char s4[] = "abcdefg";
  str_shift(s4, 3);
  EXPECT_STREQ(s4, "efgabcd");

  char s5[] = "abcdefg";
  str_shift(s5, -3);
  EXPECT_STREQ(s5, "defgabc");
  // abcdefg
  //
}

GTEST_API_ int main(int argc, char *argv[]) {
  printf("Running main() from %s\n", __FILE__);
  testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}