#include "Letters.h"

std::vector<int> Letters::Ids;

std::string centerLetter(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0) {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}
Letters::Letters(string text, int X, int Y,  int id) : InteractiveObject("Letter", id, false) {
	this->text = text;
    setX(X);
    setY(Y);
	Ids.push_back(id);
    setSymbol('?');
}
void Letters::getUIBuffer(string buffer[13]) const {
    const int width = 26;
    const int boxWidth = width + 2;

    buffer[0] = "+==^^==^^==^^==^^==^^==^^==+";


    int row = 1;
    size_t start = 0;
    while (row < 12 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerLetter(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 12) {
        buffer[row++] = "|" + centerLetter("", width) + "|";
    }
    buffer[12] = "+==^^==^^==^^==^^==^^==^^==+";
}
void Letters::use() {
    enableUI();
    //const int width = 22;

    //std::cout << "+----------------------+" << std::endl;
    //size_t start = 0;
    //while (start < text.size()) {
    //    size_t end = text.find('\n', start);
    //    if (end == std::string::npos) end = text.size();
    //    std::string line = text.substr(start, end - start);
    //    std::cout << "|" << centerLetter(line, width) << "|" << std::endl;
    //    start = end + 1;
    //}
    //std::cout << "|" << centerLetter("", width) << "|" << std::endl;
    //std::cout << "|" << centerLetter("", width) << "|" << std::endl;
    //std::cout << "+----------------------+" << std::endl;
}