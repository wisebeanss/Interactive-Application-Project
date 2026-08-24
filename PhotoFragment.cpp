#include "PhotoFragment.h"
std::string centerText(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0) {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}
vector<int> PhotoFragment::Ids;
void PhotoFragment::use() {
    const int width = 22;

    std::cout << "+----------------------+" << std::endl;
    std::cout << "|" << centerText("", width) << "|" << std::endl;
    std::cout << "|" << centerText("", width) << "|" << std::endl;
    size_t start = 0;
    while (start < description.size()) {
        size_t end = description.find('\n', start);
        if (end == std::string::npos) end = description.size();
        std::string line = description.substr(start, end - start);
        std::cout << "|" << centerText(line, width) << "|" << std::endl;
        start = end + 1;
    }
    std::cout << "|" << centerText("", width) << "|" << std::endl;
    std::cout << "|" << centerText("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
}
PhotoFragment::PhotoFragment(string Description, int X, int Y, int id) : InteractiveObject("Photo Piece", id, false){
    setX(X);
    setY(Y);
    setSymbol('~');
    description = Description;
}
PhotoFragment::~PhotoFragment() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}