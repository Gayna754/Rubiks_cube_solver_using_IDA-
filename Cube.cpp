
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

        sides[rightIndex].cornerPieces[0] = upCorner[0];
        sides[rightIndex].cornerPieces[3] = upCorner[1];
        sides[rightIndex].edgePieces[3] = upEdge;

        sides[index].cornerPieces = {currCorner[3], currCorner[0], currCorner[1], currCorner[2]};
        sides[index].edgePieces = {currEdge[3], currEdge[0], currEdge[1], currEdge[2]};

    }
    else if (sideFacing.centrePiece.colour.colourName == "green") {

        std::vector<CornerPiece> upCorner = {sides[upIndex].cornerPieces[0], sides[upIndex].cornerPieces[3]};
        EdgePiece upEdge = sides[upIndex].edgePieces[3];

        std::vector<CornerPiece> rightCorner = {sides[rightIndex].cornerPieces[0], sides[rightIndex].cornerPieces[3]};
        EdgePiece rightEdge = sides[rightIndex].edgePieces[3];

        std::vector<CornerPiece> leftCorner = {sides[leftIndex].cornerPieces[1], sides[leftIndex].cornerPieces[2]};
        EdgePiece leftEdge = sides[leftIndex].edgePieces[1];

        std::vector<CornerPiece> downCorner = {sides[downIndex].cornerPieces[0], sides[downIndex].cornerPieces[3]};
        EdgePiece downEdge = sides[downIndex].edgePieces[3];

        std::vector<CornerPiece> currCorner;
        std::vector<EdgePiece> currEdge;

        for (int i = 0; i < sides[index].cornerPieces.size(); i++) {
            currCorner.push_back(sides[index].cornerPieces[i]);
            currEdge.push_back(sides[index].edgePieces[i]);
        }

        sides[upIndex].cornerPieces[0] = leftCorner[0];
        sides[upIndex].cornerPieces[3] = leftCorner[1];
        sides[upIndex].edgePieces[3] = leftEdge;

        sides[downIndex].cornerPieces[0] = rightCorner[0];
        sides[downIndex].cornerPieces[3] = rightCorner[1];
        sides[downIndex].edgePieces[3] = rightEdge;

        sides[leftIndex].cornerPieces[1] = downCorner[0];
        sides[leftIndex].cornerPieces[2] = downCorner[1];
        sides[leftIndex].edgePieces[1] = downEdge;

        sides[rightIndex].cornerPieces[0] = upCorner[0];
        sides[rightIndex].cornerPieces[3] = upCorner[1];
        sides[rightIndex].edgePieces[3] = upEdge;

        sides[index].cornerPieces = {currCorner[3], currCorner[0], currCorner[1], currCorner[2]};
        sides[index].edgePieces = {currEdge[3], currEdge[0], currEdge[1], currEdge[2]};

    }
    else {
        U(sides[downIndex]);
    }
}

void Cube::UI(Side &sideFacing) {

    int index = indexOfSide(sideFacing);
    int rightIndex = indexOfRight(sideFacing);
    int upIndex = indexOfUp(sideFacing);
    int leftIndex = indexOfLeft(sideFacing);
    int oppIndex = indexOfOpposite(sideFacing);

    if (sideFacing.centrePiece.colour.colourName == "orange") {

        std::vector<CornerPiece> currCorner = {sides[index].cornerPieces[1], sides[index].cornerPieces[0]};
        EdgePiece currEdge = sides[index].edgePieces[0];

        std::vector<CornerPiece> rightCorner = {sides[rightIndex].cornerPieces[2], sides[rightIndex].cornerPieces[1]};
        EdgePiece rightEdge = sides[rightIndex].edgePieces[1];

        std::vector<CornerPiece> leftCorner = {sides[leftIndex].cornerPieces[3], sides[leftIndex].cornerPieces[0]};
        EdgePiece leftEdge = sides[leftIndex].edgePieces[3];

        std::vector<CornerPiece> oppCorner = {sides[oppIndex].cornerPieces[3], sides[oppIndex].cornerPieces[2]};
        EdgePiece oppEdge = sides[oppIndex].edgePieces[2];

        std::vector<CornerPiece> upCorner;
        std::vector<EdgePiece> upEdge;

        for (int i = 0; i < sides[upIndex].cornerPieces.size(); i++) {
            upCorner.push_back(sides[upIndex].cornerPieces[i]);
            upEdge.push_back(sides[upIndex].edgePieces[i]);
        }

        sides[index].cornerPieces[0] = leftCorner[0];
        sides[index].cornerPieces[1] = leftCorner[1];
        sides[index].edgePieces[0] = leftEdge;

        sides[rightIndex].cornerPieces[1] = currCorner[1];
        sides[rightIndex].cornerPieces[2] = currCorner[0];
        sides[rightIndex].edgePieces[1] = currEdge;

        sides[oppIndex].cornerPieces[2] = rightCorner[1];
        sides[oppIndex].cornerPieces[3] = rightCorner[0];
        sides[oppIndex].edgePieces[2] = rightEdge;

        sides[leftIndex].cornerPieces[0] = oppCorner[0];
        sides[leftIndex].cornerPieces[3] = oppCorner[1];
        sides[leftIndex].edgePieces[3] = oppEdge;

        sides[upIndex].cornerPieces = {upCorner[1], upCorner[2], upCorner[3], upCorner[0]};
        sides[upIndex].edgePieces = {upEdge[1], upEdge[2], upEdge[3], upEdge[0]};
    }

    else if (sideFacing.centrePiece.colour.colourName == "red") {

        std::vector<CornerPiece> currCorner = {sides[index].cornerPieces[1], sides[index].cornerPieces[0]};
        EdgePiece currEdge = sides[index].edgePieces[0];

        std::vector<CornerPiece> rightCorner = {sides[rightIndex].cornerPieces[3], sides[rightIndex].cornerPieces[0]};
        EdgePiece rightEdge = sides[rightIndex].edgePieces[3];

        std::vector<CornerPiece> leftCorner = {sides[leftIndex].cornerPieces[1], sides[leftIndex].cornerPieces[2]};
        EdgePiece leftEdge = sides[leftIndex].edgePieces[1];

        std::vector<CornerPiece> oppCorner = {sides[oppIndex].cornerPieces[2], sides[oppIndex].cornerPieces[3]};
        EdgePiece oppEdge = sides[oppIndex].edgePieces[2];

        std::vector<CornerPiece> upCorner;
        std::vector<EdgePiece> upEdge;

        for (int i = 0; i < sides[upIndex].cornerPieces.size(); i++) {
            upCorner.push_back(sides[upIndex].cornerPieces[i]);
            upEdge.push_back(sides[upIndex].edgePieces[i]);
        }

        sides[index].cornerPieces[0] = leftCorner[0];
        sides[index].cornerPieces[1] = leftCorner[1];
        sides[index].edgePieces[0] = leftEdge;

        sides[rightIndex].cornerPieces[3] = currCorner[1];
        sides[rightIndex].cornerPieces[0] = currCorner[0];
        sides[rightIndex].edgePieces[3] = currEdge;

        sides[oppIndex].cornerPieces[2] = rightCorner[0];
        sides[oppIndex].cornerPieces[3] = rightCorner[1];
        sides[oppIndex].edgePieces[2] = rightEdge;

        sides[leftIndex].cornerPieces[1] = oppCorner[0];
        sides[leftIndex].cornerPieces[2] = oppCorner[1];
        sides[leftIndex].edgePieces[1] = oppEdge;

        sides[upIndex].cornerPieces = {upCorner[1], upCorner[2], upCorner[3], upCorner[0]};
        sides[upIndex].edgePieces = {upEdge[1], upEdge[2], upEdge[3], upEdge[0]};
    }

    else {
        std::vector<CornerPiece> currCorner = {sides[index].cornerPieces[0], sides[index].cornerPieces[1]};
        EdgePiece currEdge = sides[index].edgePieces[0];

        std::vector<CornerPiece> rightCorner = {sides[rightIndex].cornerPieces[0], sides[rightIndex].cornerPieces[1]};
        EdgePiece rightEdge = sides[rightIndex].edgePieces[0];

        std::vector<CornerPiece> leftCorner = {sides[leftIndex].cornerPieces[0], sides[leftIndex].cornerPieces[1]};
        EdgePiece leftEdge = sides[leftIndex].edgePieces[0];

        std::vector<CornerPiece> oppCorner = {sides[oppIndex].cornerPieces[0], sides[oppIndex].cornerPieces[1]};
        EdgePiece oppEdge = sides[oppIndex].edgePieces[0];

        std::vector<CornerPiece> upCorner;
        std::vector<EdgePiece> upEdge;


        for (int i = 0; i < sides[upIndex].cornerPieces.size(); i++) {
            upCorner.push_back(sides[upIndex].cornerPieces[i]);
            upEdge.push_back(sides[upIndex].edgePieces[i]);
        }


        sides[index].cornerPieces[0] = leftCorner[0];
        sides[index].cornerPieces[1] = leftCorner[1];
        sides[index].edgePieces[0] = leftEdge;

        sides[rightIndex].cornerPieces[0] = currCorner[0];
        sides[rightIndex].cornerPieces[1] = currCorner[1];
        sides[rightIndex].edgePieces[0] = currEdge;

        sides[oppIndex].cornerPieces[0] = rightCorner[0];
        sides[oppIndex].cornerPieces[1] = rightCorner[1];
        sides[oppIndex].edgePieces[0] = rightEdge;

        sides[leftIndex].cornerPieces[0] = oppCorner[0];
        sides[leftIndex].cornerPieces[1] = oppCorner[1];
        sides[leftIndex].edgePieces[0] = oppEdge;

        sides[upIndex].cornerPieces = {upCorner[1], upCorner[2], upCorner[3], upCorner[0]};
        sides[upIndex].edgePieces = {upEdge[1], upEdge[2], upEdge[3], upEdge[0]};
    }

}

int Cube::indexOfSide(Side &sideToBeFound) {

    int index = 0;

    for (auto side : sides) {

            if (sideToBeFound.centrePiece.colour.colourName == side.centrePiece.colour.colourName) {
                return index;
            }

        index++;
    }

    std::cout << "Index of side not correctly found in Cube.cpp\n";

    return index;
}

int Cube::indexOfRight(Side &sideToBeFound) {

    if (sideToBeFound.centrePiece.colour.colourName == "white"
        || sideToBeFound.centrePiece.colour.colourName == "orange"
        || sideToBeFound.centrePiece.colour.colourName == "red") {
        return 4;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "yellow") {
        return 5;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "blue") {
        return 2;
    }
    else {
        return 0;
    }
}

int Cube::indexOfLeft(Side &sideToBeFound) {

    if (sideToBeFound.centrePiece.colour.colourName == "white"
        || sideToBeFound.centrePiece.colour.colourName == "orange"
        || sideToBeFound.centrePiece.colour.colourName == "red") {
        return 5;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "yellow") {
        return 4;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "blue") {
        return 0;
    }
    else {
        return 2;
    }

//    return indexOfRight(sides[indexOfRight(sides[indexOfRight(sideToBeFound)])]); // goes right 3 times
}

int Cube::indexOfUp(Side &sideToBeFound) {

    if (sideToBeFound.centrePiece.colour.colourName == "orange") {
        return 2;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "red") {
        return 0;
    }
    else {
        return 1;
    }
}

int Cube::indexOfDown(Side &sideToBeFound) {

    if (sideToBeFound.centrePiece.colour.colourName == "orange") {
        return 0;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "red") {
        return 2;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "yellow") {
        return 1;
    }
    else {
        return 3;
    }
}

int Cube::indexOfOpposite(Side &sideToBeFound) {

    if (sideToBeFound.centrePiece.colour.colourName == "white") {
        return 2;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "yellow") {
        return 0;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "green") {
        return 4;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "blue") {
        return 5;
    }
    else if (sideToBeFound.centrePiece.colour.colourName == "orange") {
        return 3;
    }
    else {
        return 1;
    }
}

void Cube::generateNewSolvedCube() {

    Side sideOne;
    Side sideTwo;
    Side sideThree;
    Side sideFour;
    Side sideFive;
    Side sideSix;

    // Centre Pieces
    CentrePiece sideOneCentre(white);
    CentrePiece sideTwoCentre(orange);
    CentrePiece sideThreeCentre(yellow);
    CentrePiece sideFourCentre(red);
    CentrePiece sideFiveCentre(blue);
    CentrePiece sideSixCentre(green);

    // Edge Pieces
    EdgePiece sideOneEdgeOne(white, orange);
    EdgePiece sideOneEdgeTwo(white, blue);
    EdgePiece sideOneEdgeThree(white, red);
    EdgePiece sideOneEdgeFour(white, green);

    EdgePiece sideThreeEdgeOne(yellow, orange);
    EdgePiece sideThreeEdgeTwo(yellow, green);
    EdgePiece sideThreeEdgeThree(yellow, red);
    EdgePiece sideThreeEdgeFour(yellow, blue);

    EdgePiece sideTwoEdgeLeft(orange, green);
    EdgePiece sideTwoEdgeRight(orange, blue);

    EdgePiece sideFourEdgeLeft(red, green);
    EdgePiece sideFourEdgeRight(red, blue);

    // Corner Pieces
    CornerPiece sideOneCornerOne(white, orange, green); //front, top/bottom, left/right
    CornerPiece sideOneCornerTwo(white, orange, blue);
    CornerPiece sideOneCornerThree(white, red, blue);
    CornerPiece sideOneCornerFour(white, red, green); //green on left

    CornerPiece sideThreeCornerOne(yellow, orange, blue);
    CornerPiece sideThreeCornerTwo(yellow, orange, green);
    CornerPiece sideThreeCornerThree(yellow, red, green);
    CornerPiece sideThreeCornerFour(yellow, red, blue);

    // White
    sideOne.centrePiece = sideOneCentre;
    sideOne.edgePieces = {sideOneEdgeOne, sideOneEdgeTwo, sideOneEdgeThree, sideOneEdgeFour};
    sideOne.cornerPieces = {sideOneCornerOne, sideOneCornerTwo, sideOneCornerThree, sideOneCornerFour};

    // Orange
    sideTwo.centrePiece = sideTwoCentre;
    sideTwo.edgePieces = {sideThreeEdgeOne.flip(), sideTwoEdgeRight, sideOneEdgeOne.flip(), sideTwoEdgeLeft};
    sideTwo.cornerPieces = {sideThreeCornerOne.top(), sideThreeCornerTwo.top(), sideOneCornerTwo.top(), sideOneCornerOne.top()};

    // Yellow
    sideThree.centrePiece = sideThreeCentre;
    sideThree.edgePieces = {sideThreeEdgeOne, sideThreeEdgeTwo, sideThreeEdgeThree, sideThreeEdgeFour};
    sideThree.cornerPieces = {sideThreeCornerOne, sideThreeCornerTwo, sideThreeCornerThree, sideThreeCornerFour};

    // Red
    sideFour.centrePiece = sideFourCentre;
    sideFour.edgePieces = {sideOneEdgeThree.flip(), sideFourEdgeRight, sideThreeEdgeThree.flip(), sideFourEdgeLeft};
    sideFour.cornerPieces = {sideOneCornerFour.top(), sideOneCornerThree.top(), sideThreeCornerFour.top(), sideThreeCornerThree.top()};

    // Blue
    sideFive.centrePiece = sideFiveCentre;
    sideFive.edgePieces = {sideTwoEdgeRight.flip(), sideThreeEdgeFour.flip(), sideFourEdgeRight.flip(), sideOneEdgeTwo.flip()};
    sideFive.cornerPieces = {sideOneCornerTwo.side(), sideThreeCornerOne.side(), sideThreeCornerFour.side(), sideOneCornerThree.side()};

    // Green
    sideSix.centrePiece = sideSixCentre;
    sideSix.edgePieces = {sideTwoEdgeLeft.flip(), sideOneEdgeFour.flip(), sideFourEdgeLeft.flip(), sideThreeEdgeTwo.flip()};
    sideSix.cornerPieces = {sideThreeCornerTwo.side(), sideOneCornerOne.side(), sideOneCornerFour.side(), sideThreeCornerThree.side()};

    sides = {sideOne, sideTwo, sideThree, sideFour, sideFive, sideSix};
}

bool Cube::solved() {
    for (auto side: sides) {
        if (!side.allSameColours()) {
            return false;
        }
    }
    return true;
}

bool Cube::whiteLayerSolved() {

    if (!sides[0].allSameColours()) {
        return false;
    }

    if (!(sides[0].cornerPieces[0].topColour.colourName == "orange" &&
          sides[0].cornerPieces[0].sideColour.colourName == "green")) {
        return false;
    }

    if (!(sides[0].cornerPieces[1].topColour.colourName == "orange" &&
          sides[0].cornerPieces[1].sideColour.colourName == "blue")) {
        return false;
    }

    if (!(sides[0].cornerPieces[2].topColour.colourName == "red" &&
          sides[0].cornerPieces[2].sideColour.colourName == "blue")) {
        return false;
    }

    if (!(sides[0].cornerPieces[3].topColour.colourName == "red" &&
          sides[0].cornerPieces[3].sideColour.colourName == "green")) {
        return false;
    }

    if (!(sides[0].edgePieces[0].otherColour.colourName == "orange" &&
          sides[0].edgePieces[1].otherColour.colourName == "blue" &&
          sides[0].edgePieces[2].otherColour.colourName == "red" &&
          sides[0].edgePieces[3].otherColour.colourName == "green")) {
        return false;
    }

    return true;
}

bool Cube::secondLayerSolved() {

    if (!(sides[1].edgePieces[1].colour.colourName == "orange" &&
          sides[1].edgePieces[3].colour.colourName == "orange")) {
        return false;
    }

    if (!(sides[3].edgePieces[1].colour.colourName == "red" &&
          sides[3].edgePieces[3].colour.colourName == "red")) {
        return false;
    }

    if (!(sides[4].edgePieces[1].colour.colourName == "blue" &&
          sides[4].edgePieces[3].colour.colourName == "blue")) {
        return false;
    }

    if (!(sides[5].edgePieces[1].colour.colourName == "green" &&
          sides[5].edgePieces[3].colour.colourName == "green")) {
        return false;
    }

    return true;
}

bool Cube::isYellowCross() {

    if (!(whiteLayerSolved() and secondLayerSolved())) {
        return false;
    }

    if (!(sides[2].edgePieces[0].colour.colourName == "yellow" &&
            sides[2].edgePieces[1].colour.colourName == "yellow" &&
            sides[2].edgePieces[2].colour.colourName == "yellow" &&
            sides[2].edgePieces[3].colour.colourName == "yellow")) {
        return false;
    }

    return true;

}

void Cube::makeYellowCross() {

    if (isYellowCross()) {
        return;
    }

    if (sides[2].edgePieces[0].colour.colourName != "yellow" &&
          sides[2].edgePieces[1].colour.colourName != "yellow" &&
          sides[2].edgePieces[2].colour.colourName != "yellow" &&
          sides[2].edgePieces[3].colour.colourName != "yellow") {

        F(sides[3]);
        R(sides[3]);
        U(sides[3]);
        RI(sides[3]);
        UI(sides[3]);
        FI(sides[3]);
        
        UI(sides[3]);
        UI(sides[3]);}