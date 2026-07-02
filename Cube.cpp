
#include "Cube.h"

#include <random>
#include <ctime>
#include <utility>
#include <cmath>
#include <unordered_set>

  std::unordered_set<std::string> visitedStates;

// Coordinates below for calculating the heuristic value 
int sideOneCoordinates[][3] = {{1, 3, 3},{2, 3, 3},{3, 3, 3},
                               {1, 2, 3},{2, 2, 3},{3, 2, 3},
                               {1, 1, 3},{2, 1, 3},{3, 1, 3}};

int sideTwoCoordinates[][3] = {{1, 3, 1},{2, 3, 1},{3, 3, 1},
                               {1, 3, 2},{2, 3, 2},{3, 3, 2},
                               {1, 3, 3},{2, 3, 3},{3, 3, 3}};

int sideThreeCoordinates[][3] = {{3, 3, 1},{2, 3, 1},{1, 3, 1},
                                 {3, 2, 1},{2, 2, 1},{1, 2, 1},
                                 {3, 1, 1},{2, 1, 1},{1, 1, 1}};         
                                 
int sideFourCoordinates[][3] = {{1, 1, 3},{2, 1, 3},{3, 1, 3},
                                {1, 1, 2},{2, 1, 2},{3, 1, 2},
                                {1, 1, 1},{2, 1, 1},{3, 1, 1}};

int sideFiveCoordinates[][3] = {{3, 3, 3},{3, 3, 2},{3, 3, 1},
                                {3, 2, 3},{3, 2, 2},{3, 2, 1},
                                {3, 1, 3},{3, 1, 2},{3, 1, 1}};          
                                
int sideSixCoordinates[][3] = {{1, 3, 1},{1, 3, 2},{1, 3, 3},
                               {1, 2, 1},{1, 2, 2},{1, 2, 3},
                               {1, 1, 1},{1, 1, 2},{1, 1, 3}};    
                               
void Cube::R(Side &sideFacing) {

    int rightIndex = indexOfRight(sideFacing);

    F(sides[rightIndex]);
}                               