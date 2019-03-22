#!/bin/bash
git commit -am "Debug"
clear
gcc -o out.exe main.c mylib.h
./out.exe