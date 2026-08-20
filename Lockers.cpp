#include "Lockers.h"

std::string centerLockerText(const std::string& text, int width)
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

vector<int> Lockers::Ids;

Lockers::Lockers(string text, int X, int Y, int id)
    : InteractiveObject("Locker", id, false)
{
    this->text = text;

    Ids.push_back(id);
    setSymbol('#');
    setX(X);
    setY(Y);
}

Lockers::~Lockers()
{
    for (size_t i = 0; i < Ids.size(); i++)
    {
        if (Ids.at(i) == getId())
        {
            Ids.erase(Ids.begin() + i);
            break;
        }
    }
}

void Lockers::use()
{
    const int width = 22;

    cout << "+----------------------+" << endl;
    cout << "|" << centerLockerText("", width) << "|" << endl;
    cout << "|" << centerLockerText("LOCKER " + to_string(getId()), width) << "|" << endl;
    cout << "|" << centerLockerText("", width) << "|" << endl;
    cout << "|" << centerLockerText(text, width) << "|" << endl;
    cout << "|" << centerLockerText("", width) << "|" << endl;
    cout << "|" << centerLockerText("", width) << "|" << endl;
    cout << "+----------------------+" << endl;
}