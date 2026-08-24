#pragma once
#include "InteractiveObject.h"

class Suitcase : public InteractiveObject
{
private:
    int noOfPhotos = 0;
    bool unlocked = false;

public:
    Suitcase(int x, int y, int id);

    bool isUnlocked();
    void collectPhoto(); 
    bool hasAllPhotos(); 
    bool tryUnlock();
    void use() override;
};