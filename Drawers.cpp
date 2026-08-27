#include "Drawers.h"
#include"Sound.h"
Sound Drawersound;
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
void Drawers::getUIBuffer(string buffer[13]) const {
    const int width = 26;
    const int boxWidth = width + 2;

    buffer[0] = "+=====--=====--=====--=====+";


    int row = 1;
    size_t start = 0;
    while (row < 12 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "[" + centerDrawerText(line, width) + "]";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 12) {
        buffer[row++] = "[" + centerDrawerText("", width) + "]";
    }
    buffer[12] = "+=====--=====--=====--=====+";
}
void Drawers::use()
{
    Drawersound.Playmirror();
    enableUI();
    /*const int width = 22;

    cout << "+----------------------+" << endl;
    cout << "|" << centerDrawerText("", width) << "|" << endl;
    cout << "|" << centerDrawerText("DRAWER " + to_string(getId()), width) << "|" << endl;
    size_t start = 0;
    while (start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        std::cout << "|" << centerDrawerText(line, width) << "|" << std::endl;
        start = end + 1;
    }
    cout << "|" << centerDrawerText("", width) << "|" << endl;
    cout << "+----------------------+" << endl;*/
}