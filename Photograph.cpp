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
void Photograph::getUIBuffer(string buffer[13]) const {
    const int width = 23;
    const int boxWidth = width + 2;

    buffer[0] = "+--~-~-~-~-~-~-~-~-~-~--+";
    buffer[1] = "|  .---.                |";
    buffer[2] = "| /     \\     /\\        |";
    buffer[3] = "||   o   |   /  \\   /\\  |";
    buffer[4] = "| \\     /   /    \\ /  \\ | ";
    buffer[5] = "|  '---'   /      V    \\|";
    buffer[6] = "|~~~~~~~~~/~~~~~~~~~~~~~|";


    int row = 7;
    size_t start = 0;
    while (row < 12 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerPhotoText(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 12) {
        buffer[row++] = "|" + centerPhotoText("", width) + "|";
    }
    buffer[12] = "+--~-~-~-~-~-~-~-~-~-~--+";
}

void Photograph::use()
{
    enableUI();
    //const int width = 22;

    //cout << "+----------------------+" << endl;
    //cout << "|" << centerPhotoText("", width) << "|" << endl;
    //cout << "|" << centerPhotoText(text, width) << "|" << endl;
    //cout << "|" << centerPhotoText("", width) << "|" << endl;
    //cout << "+----------------------+" << endl;
}