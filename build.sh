#! /bin/bash

g++ -I$(dirname $0)/inc $(dirname $0)/main.cpp $(dirname $0)/element.cpp -o $(dirname $0)/main && $(dirname $0)/main
