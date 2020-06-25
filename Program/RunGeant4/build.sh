#!/bin/bash
echo "build RunGeant4 ver9"
ls
g++ -c -pthread AutoRun.cpp BuildG4Proj.cpp Class.cpp Constant.cpp FileIO.cpp Gathering.cpp MakeDir.cpp Process.cpp CreateFile.cpp
g++ -Wall -w -o2 -o RunGeant4 main.cpp AutoRun.o BuildG4Proj.o Class.o Constant.o FileIO.o Gathering.o MakeDir.o Process.o CreateFile.o -pthread
echo "build end"
