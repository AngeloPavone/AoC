#!/usr/bin/env bash

set -xe

CFLAGS="-Wall -Wextra"

clang $CFLAGS -o calorie-counting main.c

./calorie-counting
