#pragma once
#include "InteractiveObject.h"

class Suitcase : public InteractiveObject
{
private:
    bool photo1 = false; // 第1张标记
    bool photo2 = false; // 第2张标记
    bool photo3 = false; // 第3张标记
    bool unlocked = false;

public:
    Suitcase(int x, int y, int id);

    bool isUnlocked();
    void collectPhoto(int num); 
    bool hasAllPhotos(); 
    bool tryUnlock();
    void use() override;
};