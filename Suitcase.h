#pragma once
#include "InteractiveObject.h"

class Suitcase : public InteractiveObject
{
private:
    int roomID;
    bool unlocked;
    int noOfPhotos;
    bool puzzleSolved;
    int progressState;
    bool canunlock;

public:
    Suitcase(int x, int y, int id, int room = 1);

    bool isUnlocked();
    void use() override;

    void collectPhoto();
    void markPuzzleSolved();
    void setProgressState(int s);
    bool hasAllPhotos();
    bool tryUnlock();
};