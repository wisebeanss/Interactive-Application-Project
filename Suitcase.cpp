#include "Suitcase.h"
#include <iostream>
#include <string>
using namespace std;

Suitcase::Suitcase(int x, int y, int id)
    : InteractiveObject("Suitcase", id, false)
{
    setX(x);
    setY(y);
    setSymbol(']');
}

bool Suitcase::isUnlocked() 
{
    return unlocked;
}

void Suitcase::collectPhoto()
{
    noOfPhotos = noOfPhotos + 1;
}
bool Suitcase::hasAllPhotos()
{
    if (noOfPhotos == 3) { return true; }
    else { return false; }
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
    else
    {
        cout << "\nThe suitcase is still locked. Find all 3 photos first.\n";
        cout << "Pieces collected: " << noOfPhotos << "/3\n";
        return false;
    }
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