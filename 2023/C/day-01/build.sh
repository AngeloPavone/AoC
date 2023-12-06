#! /usr/bin/env bash

set -xe

set CFLAGS="-Wall -Wextra"

clang $CFLAGS -o part1 part1.c
clang $CFLAGS -o part2 part2.c
