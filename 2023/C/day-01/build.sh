#! /usr/bin/env bash

set -xe

set CFLAGS="-std=C2x -Wall -Wextra -ggdb"

clang $CFLAGS -o part1 part1.c
clang $CFLAGS -o part2 part2.c
