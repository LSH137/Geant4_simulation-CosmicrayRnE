#!/bin/bash
echo "build compareHistogram ver9"
ls
g++ -c -pthread dataStructure.cpp constant.cpp File.cpp WhoInThere.cpp
g++ -Wall -w -o2 -o CompareHistogram main.cpp dataStructure.o constant.o File.o WhoInThere.o -pthread
echo "build end"
