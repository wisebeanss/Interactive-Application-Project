#include "Clocks.h"
Clocks::Clocks(string text,int x , int y, int id) : InteractiveObject("Clock", id, false)
{
	this->text = text;
    Ids.push_back(id);
	setX(x);
	setY(y);
	setSymbol('@');
}
vector<int> Clocks::Ids;
Clocks::~Clocks()
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
//void Clocks::setLine(string lines)
//{
//	line = lines;
//}
string Clocks::centerClockText(const string& str, int width) const {
	int padding = width - static_cast<int>(str.size());

	if (padding <= 0)
	{
		return str.substr(0, width);
	}

	int left = padding / 2;
	int right = padding - left;

	return std::string(left, ' ') + str + std::string(right, ' ');
}
void Clocks::getUIBuffer(string buffer[13]) const {
    const int width = 21;
    const int boxWidth = width + 2;

    buffer[0] = "                     ";
    buffer[1] = "  ___________________";
    buffer[2] = " /                   \\";


    int row = 3;
    size_t start = 0;
    while (row < 9 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerClockText(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 9) {
        buffer[row++] = "|" + centerClockText("", width) + "|";
    }
    buffer[9] = " \\___________________/";
    buffer[10] = "   *^*^*^*^*^*^*^*^*  ";
    buffer[11] = "                     ";
    buffer[12] = "                     ";
}
void Clocks::use()
{
	enableUI();
}