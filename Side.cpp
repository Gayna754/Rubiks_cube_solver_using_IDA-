#include "Side.h"


bool Side::allSameColours() {
    for (auto edgePiece: edgePieces) {
        if (edgePiece.colour.colourName != centrePiece.colour.colourName) {
            return false;
        }
    }
}