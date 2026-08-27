#include "Phones.h"
#include"Sound.h"
Sound Phonering;
std::string centerPhoneText(const std::string& text, int width)
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

vector<int> Phones::Ids;

Phones::Phones(string text, int X, int Y, int id)
    : InteractiveObject("Phone", id, false)
{
    this->text = text;

    Ids.push_back(id);
    setSymbol('A');
    setX(X);
    setY(Y);
}

Phones::~Phones()
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
void Phones::getUIBuffer(string buffer[13]) const {
    const int width = 13;
    const int boxWidth = width + 2;

    buffer[0] = "+-===========-+";

    int row = 1;
    size_t start = 0;
    while (row < 9 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerPhoneText(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 9) {
        buffer[row++] = "|" + centerPhoneText("", width) + "|";
    }
    buffer[9] = "|     ()      |";
    buffer[10] = "+-===========-+";
    buffer[11] = "                      ";
    buffer[12] = "                      ";
}

void Phones::use()
{
    Phonering.PlayPhone();
    enableUI();
    //const int width = 22;

    //cout << "+----------------------+" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("PHONE ", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText(text, width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "|" << centerPhoneText("", width) << "|" << endl;
    //cout << "+----------------------+" << endl;
}