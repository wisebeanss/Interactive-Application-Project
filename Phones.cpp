#include "Phones.h"


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

void Phones::use()
{
    const int width = 22;

    cout << "+----------------------+" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("PHONE ", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText(text, width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "|" << centerPhoneText("", width) << "|" << endl;
    cout << "+----------------------+" << endl;
}