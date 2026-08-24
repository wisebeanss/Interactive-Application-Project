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
void PhotoFragment::getUIBuffer(string buffer[13]) const {
    const int width = 26;
    const int boxWidth = width + 2;

    buffer[0] = "                      ";
    buffer[1] = "                      ";
    buffer[2] = "+--~-~-~-~-~-~-~-~-~-~-~-~-+";
    buffer[3] = "|--------------------------|";
    

    int row = 4;
    size_t start = 0;
    while (row < 9 && start < description.size()) {
        size_t end = description.find('\n', start);
        if (end == std::string::npos) end = description.size();
        std::string line = description.substr(start, end - start);
        buffer[row++] = "|" + centerText(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 9) {
        buffer[row++] = "|" + centerText("", width) + "|";
    }
    buffer[9] = "+--~-~-~-~-~-~-~-~-~-~-~-~-+";
    buffer[10] = "                      ";
    buffer[11] = "                      ";
    buffer[12] = "                      ";
}
void PhotoFragment::use() {
    enableUI();
    //const int width = 22;

    //std::cout << "+----------------------+" << std::endl;
    //std::cout << "|" << centerText("", width) << "|" << std::endl;
    //std::cout << "|" << centerText("", width) << "|" << std::endl;
    //size_t start = 0;
    //while (start < description.size()) {
    //    size_t end = description.find('\n', start);
    //    if (end == std::string::npos) end = description.size();
    //    std::string line = description.substr(start, end - start);
    //    std::cout << "|" << centerText(line, width) << "|" << std::endl;
    //    start = end + 1;
    //}
    //std::cout << "|" << centerText("", width) << "|" << std::endl;
    //std::cout << "|" << centerText("", width) << "|" << std::endl;
    //std::cout << "+----------------------+" << std::endl;
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
