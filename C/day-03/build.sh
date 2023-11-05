#!/usr/bin/env bash

set -xe

CFLAGS="--std=c17 -Wall -Wextra"

clang $CFLAGS -o main main.c