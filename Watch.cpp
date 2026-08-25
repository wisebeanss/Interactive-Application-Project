#include "Watch.h"
std::string Watch::centerWatchText(const std::string& text, int width) const
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
    setSymbol('@');
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

void Watch::getUIBuffer(string buffer[13]) const {
    const int width = 26;
    const int boxWidth = width + 2;

    buffer[0] = "        |        |      ";
    buffer[1] = "        |        |      ";
    buffer[2] = "+--~-~-~-~-~-~-~-~-~-~-~-~-+";


    int row = 3;
    size_t start = 0;
    while (row < 9 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerWatchText(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 9) {
        buffer[row++] = "|" + centerWatchText("", width) + "|";
    }
    buffer[9] = "+--~-~-~-~-~-~-~-~-~-~-~-~-+";
    buffer[10] = "        |        |      ";
    buffer[11] = "        |        |      ";
    buffer[12] = "        |        |      ";
}

void Watch::use()
{
    enableUI();
    /*const int width = 22;
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
    cout << "         |    |" << endl;*/
}