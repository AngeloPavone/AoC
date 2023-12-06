#!/usr/bin/env bash

set -xe

CFLAGS="--std=c17 -Wall -Wextra"

clang $CFLAGS -o part1 part1.c
clang $CFLAGS -o part2 part2.c
