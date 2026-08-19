#include "Mirrors.h"
std::string centerMirrorText(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0) {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}
vector<int> Mirrors::Ids;
Mirrors::Mirrors(string text, int id) : InteractiveObject("Note", id) {
    this->text = text;
    Ids.push_back(id);
}
Mirrors::~Mirrors() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}
void Mirrors::use() {
    const int width = 22;
    const int boxWidth = width + 2;
    for (int w = 2; w <= width; w += 2) {
        std::string line = "/" + std::string(w - 2, ' ') + "\\";
        std::cout << centerMirrorText(line, boxWidth) << std::endl;
    }
    std::cout << "+----------------------+" << std::endl;
    std::cout << "+----------------------+" << std::endl;
    std::cout << "|" << centerMirrorText("", width) << "|" << std::endl;
    std::cout << "|" << centerMirrorText(text, width) << "|" << std::endl;
    std::cout << "|" << centerMirrorText("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
    for (int w = width; w  >= 2; w -= 2) {
        std::string line = "\\" + std::string(w - 2, ' ') + "/";
        std::cout << centerMirrorText(line, boxWidth) << std::endl;
    }
}