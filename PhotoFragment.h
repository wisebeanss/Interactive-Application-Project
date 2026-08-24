#pragma once
#include "InteractiveObject.h"
#include <vector>
#include <string>

class PhotoFragment : public InteractiveObject
{
private:
    std::string description;

public:
    PhotoFragment(std::string description, int X, int Y, int id);
    ~PhotoFragment();

    static std::vector<int> Ids;

    static bool allCollected() { return Ids.size() >= 3; }
    static int getCollectedCount() { return static_cast<int>(Ids.size()); } 
    static void markCollected(int id) { Ids.push_back(id); }
    static void resetCollection() { Ids.clear(); }

    void use();
};

