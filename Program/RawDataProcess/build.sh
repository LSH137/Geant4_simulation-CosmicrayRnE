#!/bin/bash
echo "build RawDataProcess ver9"
ls
g++ -c -pthread Class.cpp Constant.cpp FileIO.cpp Gathering.cpp Process.cpp
g++ -Wall -w -o2 -o RawDataProcess main.cpp Class.o Constant.o FileIO.o Gathering.o Process.o -pthread
echo "build end"
