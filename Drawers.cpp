#include "Drawers.h"

std::string centerDrawerText(const std::string& text, int width)
{
    int padding = width - static_cast<int>(text.size());

    if (padding <= 0)
    {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}

vector<int> Drawers::Ids;

Drawers::Drawers(string text, int X, int Y, int id)
    : InteractiveObject("Drawer", id, false)
{
    this->text = text;

    Ids.push_back(id);
    setSymbol('#');
    setX(X);
    setY(Y);
}

Drawers::~Drawers()
{
    for (size_t i = 0; i < Ids.size(); i++)
    {
        if (Ids.at(i) == getId())
        {
            Ids.erase(Ids.begin() + i);
        }
    }
}

void Drawers::use()
{
    const int width = 22;

    cout << "+----------------------+" << endl;
    cout << "|" << centerDrawerText("", width) << "|" << endl;
    cout << "|" << centerDrawerText("DRAWER " + to_string(getId()), width) << "|" << endl;
    cout << "|" << centerDrawerText("", width) << "|" << endl;
    cout << "|" << centerDrawerText(text, width) << "|" << endl;
    cout << "|" << centerDrawerText("", width) << "|" << endl;
    cout << "+----------------------+" << endl;
}