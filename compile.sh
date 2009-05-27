#!/bin/sh



g++ -I/usr/include/boost -I/usr/include/python2.5 -lboost_python -L/usr/lib -lpython2.5 Main.cpp PyTest.cpp -o test