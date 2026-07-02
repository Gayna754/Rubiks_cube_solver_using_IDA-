
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

void Cube::L(Side &sideFacing) {

    int leftIndex = indexOfLeft(sideFacing);

    F(sides[leftIndex]);
}

void Cube::D(Side &sideFacing) {

    int downIndex = indexOfDown(sideFacing);

    F(sides[downIndex]);
}

void Cube::B(Side &sideFacing) {

    int oppIndex = indexOfOpposite(sideFacing);

    F(sides[oppIndex]);
}

void Cube::F(Side &sideFacing) {

    int index = indexOfSide(sideFacing);
    int rightIndex = indexOfRight(sideFacing);
    int upIndex = indexOfUp(sideFacing);
    int leftIndex = indexOfLeft(sideFacing);
    int downIndex = indexOfDown(sideFacing);

 if (sideFacing.centrePiece.colour.colourName == "red") { //wrong

        std::vector<CornerPiece> upCorner = {sides[upIndex].cornerPieces[2], sides[upIndex].cornerPieces[3]};
        EdgePiece upEdge = sides[upIndex].edgePieces[2];

        std::vector<CornerPiece> rightCorner = {sides[rightIndex].cornerPieces[2], sides[rightIndex].cornerPieces[3]};
        EdgePiece rightEdge = sides[rightIndex].edgePieces[2];

        std::vector<CornerPiece> leftCorner = {sides[leftIndex].cornerPieces[2], sides[leftIndex].cornerPieces[3]};
        EdgePiece leftEdge = sides[leftIndex].edgePieces[2];

        std::vector<CornerPiece> downCorner = {sides[downIndex].cornerPieces[2], sides[downIndex].cornerPieces[3]};
        EdgePiece downEdge = sides[downIndex].edgePieces[2];
}