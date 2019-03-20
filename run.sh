#!/bin/bash
git add --all
git commit -m "Debug"
clear
gcc -o out.exe main.c mylib.h
./out.exe