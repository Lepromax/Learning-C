#!/bin/bash
git add --all
git commit -m "Debug"

gcc -o out.exe main.c mylib.h
./out.exe