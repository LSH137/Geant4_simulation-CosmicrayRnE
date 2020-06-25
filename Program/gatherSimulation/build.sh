#!/bin/bash
echo "build GatherSimulatedData ver9"
ls
g++ -c -pthread Class.cpp Constant.cpp FileIO.cpp Gathering.cpp 
g++ -Wall -w -m64 -o2 -o GatherSimulatedData main.cpp Class.o Constant.o FileIO.o Gathering.o -pthread
echo "build end"
