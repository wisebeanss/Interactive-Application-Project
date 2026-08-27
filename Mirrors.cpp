#include "Mirrors.h"
#include"Sound.h"
Sound Mirrorplace;
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
    setSymbol('&');
}
Mirrors::~Mirrors() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}
void Mirrors::use() {
    Mirrorplace.Playmirror();
    enableUI();
}

void Mirrors::getUIBuffer(string buffer[13]) const {
    const int width = 26;
    const int boxWidth = width + 2;

    buffer[0] = centerMirrorText("/\\", boxWidth);
    buffer[1] = centerMirrorText("/  \\", boxWidth);
    buffer[2] = centerMirrorText("/    \\", boxWidth);
    buffer[3] = "+--------------------------+";

    int row = 4;
    size_t start = 0;
    while (row < 9 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == string::npos) end = text.size();
        string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerMirrorText(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 9) {
        buffer[row++] = "|" + centerMirrorText("", width) + "|";
    }
    buffer[9] = "+--------------------------+";
    buffer[10] = centerMirrorText("\\    /", boxWidth);
    buffer[11] = centerMirrorText("\\  /", boxWidth);
    buffer[12] = centerMirrorText("\\/", boxWidth);
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
