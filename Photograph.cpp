#include "Photograph.h"
#include <iostream>

using namespace std;

string centerPhotoText(const string& text, int width)
{
    int padding = width - static_cast<int>(text.size());

    if (padding <= 0)
    {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return string(left, ' ') + text + string(right, ' ');
}

vector<int> Photograph::Ids;

Photograph::Photograph(string text, int X, int Y, int id)
    : InteractiveObject("Photograph", id, false)
{
    this->text = text;
    setSymbol('~');
    Ids.push_back(id);

    setX(X);
    setY(Y);
}

Photograph::~Photograph()
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

void Photograph::use()
{
    const int width = 22;

    cout << "+----------------------+" << endl;
    cout << "|" << centerPhotoText("", width) << "|" << endl;
    cout << "|" << centerPhotoText(text, width) << "|" << endl;
    cout << "|" << centerPhotoText("", width) << "|" << endl;
    cout << "+----------------------+" << endl;
}