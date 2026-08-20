#include "Watch.h"
std::string centerWatchText(const std::string& text, int width)
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

vector<int> Watch::Ids;

Watch::Watch(string text, int X, int Y, int id)
    : InteractiveObject("Watch", id, false)
{
    this->text = text;

    Ids.push_back(id);

    setX(X);
    setY(Y);
}

Watch::~Watch()
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

void Watch::use()
{
    const int width = 22;
    cout << "         |    |" << endl;
    cout << "         |    |" << endl;
    cout << "+----------------------+" << endl;
    cout << "|" << centerWatchText("", width) << "|" << endl;
    cout << "|" << centerWatchText("WATCH ", width) << "|" << endl;
    cout << "|" << centerWatchText("", width) << "|" << endl;
    cout << "|" << centerWatchText(text, width) << "|" << endl;
    cout << "|" << centerWatchText("", width) << "|" << endl;
    cout << "|" << centerWatchText("", width) << "|" << endl;
    cout << "+----------------------+" << endl;
    cout << "         |    |" << endl;
    cout << "         |    |" << endl;
}