#pragma once
#include <string>
#include <vector>

class Dialogue
{
private:
    int typingSpeed;

public:
    Dialogue();

    void show(const std::vector<std::string>& lines);
};
