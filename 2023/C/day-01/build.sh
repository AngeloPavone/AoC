#! /usr/bin/env bash

set -xe

set CFLAGS="-std=C20 -Wall -Wextra -ggdb"

clang $CFLAGS -o part1 part1.c
clang $CFLAGS -o part2 part2.c
