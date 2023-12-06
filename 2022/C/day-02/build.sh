#!/usr/bin/env bash

set -xe

CFLAGS="-Wall -Wextra"

clang $CFLAGS -o rock-paper-scissors main.c

./rock-paper-scissors 