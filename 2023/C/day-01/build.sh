#!/usr/bin/env bash

set -xe

CFLAGS="-std=c2x -Wall -Wextra -g -pedantic"

gcc $CFLAGS -o part1 part1.c
gcc $CFLAGS -o part2 part2.c
