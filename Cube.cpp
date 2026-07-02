
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

        std::vector<CornerPiece> currCorner;
        std::vector<EdgePiece> currEdge;

        for (int i = 0; i < sides[index].cornerPieces.size(); i++) {
            currCorner.push_back(sides[index].cornerPieces[i]);
            currEdge.push_back(sides[index].edgePieces[i]);
        }

        sides[upIndex].cornerPieces[2] = leftCorner[0];
        sides[upIndex].cornerPieces[3] = leftCorner[1];
        sides[upIndex].edgePieces[2] = leftEdge;

        sides[downIndex].cornerPieces[2] = rightCorner[0];
        sides[downIndex].cornerPieces[3] = rightCorner[1];
        sides[downIndex].edgePieces[2] = rightEdge;

        sides[leftIndex].cornerPieces[2] = downCorner[0];
        sides[leftIndex].cornerPieces[3] = downCorner[1];
        sides[leftIndex].edgePieces[2] = downEdge;

        sides[rightIndex].cornerPieces[2] = upCorner[0];
        sides[rightIndex].cornerPieces[3] = upCorner[1];
        sides[rightIndex].edgePieces[2] = upEdge;

        sides[index].cornerPieces = {currCorner[3], currCorner[0], currCorner[1], currCorner[2]};
        sides[index].edgePieces = {currEdge[3], currEdge[0], currEdge[1], currEdge[2]};

    }
    else if (sideFacing.centrePiece.colour.colourName == "blue") {

        std::vector<CornerPiece> upCorner = {sides[upIndex].cornerPieces[1], sides[upIndex].cornerPieces[2]};
        EdgePiece upEdge = sides[upIndex].edgePieces[1];

        std::vector<CornerPiece> rightCorner = {sides[rightIndex].cornerPieces[0], sides[rightIndex].cornerPieces[3]};
        EdgePiece rightEdge = sides[rightIndex].edgePieces[3];

        std::vector<CornerPiece> leftCorner = {sides[leftIndex].cornerPieces[1], sides[leftIndex].cornerPieces[2]};
        EdgePiece leftEdge = sides[leftIndex].edgePieces[1];

        std::vector<CornerPiece> downCorner = {sides[downIndex].cornerPieces[1], sides[downIndex].cornerPieces[2]};
        EdgePiece downEdge = sides[downIndex].edgePieces[1];

       std::vector<CornerPiece> currCorner;
        std::vector<EdgePiece> currEdge;

        for (int i = 0; i < sides[index].cornerPieces.size(); i++) {
            currCorner.push_back(sides[index].cornerPieces[i]);
            currEdge.push_back(sides[index].edgePieces[i]);
        }

        sides[upIndex].cornerPieces[1] = leftCorner[0];
        sides[upIndex].cornerPieces[2] = leftCorner[1];
        sides[upIndex].edgePieces[1] = leftEdge;

        sides[downIndex].cornerPieces[1] = rightCorner[0];
        sides[downIndex].cornerPieces[2] = rightCorner[1];
        sides[downIndex].edgePieces[1] = rightEdge;

        sides[leftIndex].cornerPieces[1] = downCorner[0];
        sides[leftIndex].cornerPieces[2] = downCorner[1];
        sides[leftIndex].edgePieces[1] = downEdge;
    }