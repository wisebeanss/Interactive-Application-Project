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
Mirrors::Mirrors(string text, int X, int Y, int id) : InteractiveObject("Note", id, false) {
    this->text = text;
    Ids.push_back(id);
    setX(X);
    setY(Y);
}
Mirrors::~Mirrors() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}
void Mirrors::use() {
    enableUI();
}

void Mirrors::getUIBuffer(string buffer[13]) const {
    const int width = 22;
    const int boxWidth = width + 2;

    buffer[0] = centerMirrorText("/\\", boxWidth);
    buffer[1] = centerMirrorText("/  \\", boxWidth);
    buffer[2] = centerMirrorText("/    \\", boxWidth);
    buffer[3] = "+----------------------+";
    buffer[4] = "|" + centerMirrorText("", width) + "|";
    buffer[5] = "|" + centerMirrorText(text, width) + "|";
    buffer[6] = "|" + centerMirrorText("", width) + "|";
    buffer[7] = "+----------------------+";
    buffer[8] = centerMirrorText("\\    /", boxWidth);
    buffer[9] = centerMirrorText("\\  /", boxWidth);
    buffer[10] = centerMirrorText("\\/", boxWidth);
    buffer[11] = "                      ";
    buffer[12] = "                      ";
}

string Mirrors::centerMirrorText(string str, int width) const {
    int padding = width - (int)str.length();
    if (padding <= 0) return str;
    int leftPad = padding / 2;
    int rightPad = padding - leftPad;
    return string(leftPad, ' ') + str + string(rightPad, ' ');
}

    /*const std::string rightOffset = "                                                                                    ";
    for (int w = 2; w <= width; w += 2) {
        std::string line = "/" + std::string(w - 2, ' ') + "\\";
        std::cout << rightOffset << centerMirrorText(line, boxWidth) << std::endl;
    }
    std::cout << rightOffset << "+----------------------+" << std::endl;
    std::cout << rightOffset << "|" << centerMirrorText("", width) << "|" << std::endl;
    std::cout << rightOffset << "|" << centerMirrorText(text, width) << "|" << std::endl;
    std::cout << rightOffset << "|" << centerMirrorText("", width) << "|" << std::endl;
    std::cout << rightOffset << "+----------------------+" << std::endl;
    for (int w = width; w  >= 2; w -= 2) {
        std::string line = "\\" + std::string(w - 2, ' ') + "/";
        std::cout << rightOffset << centerMirrorText(line, boxWidth) << std::endl;
    }*/
