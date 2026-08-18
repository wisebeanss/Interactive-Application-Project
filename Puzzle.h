#pragma once
#include "InteractiveObject.h"
class Puzzle :
    public InteractiveObject
{
    // Puzzle functions
    void sequencePuzzle(int roomID);
    void identifyObjectPuzzle(int roomID);
    void fragmentPuzzle(int roomID);
    void orderingPuzzle(int roomID);
    void deductionPuzzle(int roomID);
    void choicePuzzle(int roomID);

   

};

