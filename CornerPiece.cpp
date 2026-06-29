
#include "CornerPiece.h"

#include "iostream"
#include "Colour.h"
#include "vector"
#include <utility>
 

CornerPiece::CornerPiece(Colour colourFront, Colour colourTop, Colour colourSide) {
    colour = colourFront;
    topColour = colourTop;
    sideColour = colourSide;
    colours = {colour, topColour, sideColour};
}