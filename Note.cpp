#include "Note.h"
std::string centerDescription(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0) {
        return text.substr(0, width);
    }

	int left = padding / 2;
	int right = padding - left;

	return std::string(left, ' ') + text + std::string(right, ' ');
}
vector<int> Note::Ids;
Note::Note(string text, int X, int Y, int id) : InteractiveObject("Note", id, true) {
    this->text = text;
    Ids.push_back(id);
    setX(X);
    setY(Y);
    setSymbol('^');
}
Note::~Note() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}
void Note::getUIBuffer(string buffer[13]) const {
    const int width = 26;
    const int boxWidth = width + 2;

    buffer[0] = "+--~-~-~-~-~-~-~-~-~-~-~-~-+";


    int row = 1;
    size_t start = 0;
    while (row < 12 && start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        buffer[row++] = "|" + centerDescription(line, width) + "|";
        start = end + 1; // move past '\n'
    }
    // Fill remaining rows with empty centered lines
    while (row < 12) {
        buffer[row++] = "|" + centerDescription("", width) + "|";
    }
    buffer[12] = "+--~-~-~-~-~-~-~-~-~-~-~-~-+";
}
void Note::use() {
    enableUI();
}
    //const int width = 22;

    //std::cout << "+----------------------+" << std::endl;
    //std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    //std::cout << "|" << centerDescription("", width) << "|" << std::endl;

    //size_t start = 0;
    //while (start < text.size()) {
    //    size_t end = text.find('\n', start);
    //    if (end == std::string::npos) end = text.size();
    //    std::string line = text.substr(start, end - start);
    //    std::cout << "|" << centerDescription(line, width) << "|" << std::endl;
//    //    start = end + 1;
//    //}
//
//    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
//    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
//    std::cout << "+----------------------+" << std::endl;
//}