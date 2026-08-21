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
void Letters::use() {
    const int width = 22;

    std::cout << "+----------------------+" << std::endl;
    std::cout << "|" << centerLetter("", width) << "|" << std::endl;
    std::cout << "|" << centerLetter("", width) << "|" << std::endl;
    std::cout << "|" << centerLetter(text, width) << "|" << std::endl;
    std::cout << "|" << centerLetter("", width) << "|" << std::endl;
    std::cout << "|" << centerLetter("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
}