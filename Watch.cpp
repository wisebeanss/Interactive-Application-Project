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

void Watch::getUIBuffer(string buffer[15]) const
{
    const int width = 22;

    buffer[0] = "         |    |";
    buffer[1] = "         |    |";
    buffer[2] = "+----------------------+";

    int row = 3;
    buffer[row++] = "|" + centerWatchText("WATCH ", width) + "|";
    size_t start = 0;
    while (row < 9 && start < text.size())
    {
        size_t end = text.find('\n', start);
        if (end == string::npos)
        {
            end = text.size();
        }

        string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerWatchText(line, width) + "|";
        start = end + 1;
    }

    while (row < 9)
    {
        buffer[row++] = "|" + centerWatchText("", width) + "|";
    }

    buffer[9] = "+----------------------+";
    buffer[10] = "         |    |";
    buffer[11] = "         |    |";

    // Clear unused rows
    for (int i = 12; i < 15; i++)
    {
        buffer[i] = "";
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