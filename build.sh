#!/bin/bash
cd "$(dirname "$0")"
make clean && make && ./build/main
