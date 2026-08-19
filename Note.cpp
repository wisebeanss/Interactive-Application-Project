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
Note::Note(string text, int id) : InteractiveObject("Note", id) {
    this->text = text;
    Ids.push_back(id);
}
Note::~Note() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}
void Note::use() {
    const int width = 22;

    std::cout << "+----------------------+" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription(text, width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
}