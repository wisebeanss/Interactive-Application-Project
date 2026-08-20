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
    std::cout << "|" << centerText(description, width) << "|" << std::endl;
    std::cout << "|" << centerText("", width) << "|" << std::endl;
    std::cout << "|" << centerText("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
}
PhotoFragment::PhotoFragment(string description, int id) : InteractiveObject("Photo Fragment", id, false){
    setSymbol('~');
}
PhotoFragment::~PhotoFragment() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}