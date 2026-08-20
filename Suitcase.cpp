#include "Suitcase.h"
#include <iostream>

using namespace std;
Suitcase::Suitcase(int x, int y, int id)
    : InteractiveObject("Suitcase", id , false)
{
    setX(x);
    setY(y);

}

void Suitcase::collectPhoto(int num)
{
    if (num == 1) photo1 = true;
    if (num == 2) photo2 = true;
    if (num == 3) photo3 = true;

    if (photo1 && photo2 && photo3) {
        unlocked = true;
    }
}
bool Suitcase::isUnlocked() const { return unlocked; }
bool Suitcase::hasAllPhotos()
{
    return photo1 && photo2 && photo3;
}

bool Suitcase::tryUnlock()
{
    if (hasAllPhotos())
    {
        cout << "A hand reaching out.\n";
        cout << "A face turned away.\n";
        cout << "Someone sitting beside you.\n";
        cout << "You stare at the completed image.\n";
        cout << "Was I really there?\n";
        unlocked = true;
        return true;
    }
    cout << "\n The suitcase is still locked. Find all 3 photos first.\n";
    return false;
}