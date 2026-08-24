#include "Suitcase.h"
#include <iostream>
#include <string>
using namespace std;

Suitcase::Suitcase(int x, int y, int id)
    : InteractiveObject("Suitcase", id, false), photo1(false),
    photo2(false),
    photo3(false),
    unlocked(false)
{
    setX(x);
    setY(y);
    setSymbol(']');
}

bool Suitcase::isUnlocked() 
{
    return unlocked;
}

void Suitcase::collectPhoto(int num)
{
    if (num == 1) photo1 = true;
    if (num == 2) photo2 = true;
    if (num == 3) photo3 = true;
}

bool Suitcase::hasAllPhotos()
{
    return photo1 && photo2 && photo3;
}

bool Suitcase::tryUnlock()
{
    if (hasAllPhotos()) 
    {
        cout << "\r" << string(80, ' ') << "\r";
        cout << "A hand reaching out.\n";
        cout << "A face turned away.\n";
        cout << "Someone sitting beside you.\n";
        cout << "You stare at the completed image.\n";
        cout << "Was I really there?\n";

        unlocked = true;
        cout << "\n📝A note has appeared nearby.\n";
        return true;
    }

  
    int count = (photo1 ? 1 : 0) + (photo2 ? 1 : 0) + (photo3 ? 1 : 0);
    cout << "\nThe suitcase is still locked. Find all 3 photos first.\n";
    cout << "Pieces collected: " << count << "/3\n";
    return false;
}

void Suitcase::use()
{
    cout << "\r" << string(80, ' ') << "\r";

    if (isUnlocked())
    {
        cout << "The suitcase is already open.\n";
        cout << "Read the note nearby.\n";
        return;
    }

    tryUnlock();
}