#pragma once
#include "InteractiveObject.h"
#include<string>

class Puzzle :
    public InteractiveObject
{
    // Puzzle functions
    void sequencePuzzle(int roomID);
    bool  identifyObjectPuzzle(int roomID);
    bool  fragmentPuzzle(int roomID);
    bool  orderingPuzzle(int roomID);
    bool  deductionPuzzle(int roomID);
    bool  choicePuzzle(int roomID);

   

};

