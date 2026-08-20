#pragma once
#include "InteractiveObject.h"

class Suitcase : public InteractiveObject
{
private:
    bool photo1 = false;
    bool photo2 = false;
    bool photo3 = false;
    bool unlocked = false;

public:
    Suitcase(int x, int y, int id);
    void collectPhoto(int num);
    bool hasAllPhotos();
    bool tryUnlock();
    bool isUnlocked() const;
}