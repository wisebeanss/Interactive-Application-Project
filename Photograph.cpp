#include "Photograph.h"
std::string CenterpgText(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0) {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}
vector<int> Photograph::Ids;
void Photograph::use() {
    const int width = 22;

    std::cout << "+----------------------+" << std::endl;
    std::cout << "|" << CenterpgText("", width) << "|" << std::endl;
    std::cout << "|" << CenterpgText("", width) << "|" << std::endl;
    std::cout << "|" << CenterpgText(description, width) << "|" << std::endl;
    std::cout << "|" << CenterpgText("", width) << "|" << std::endl;
    std::cout << "|" << CenterpgText("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
}
Photograph::Photograph(string description, int id) : InteractiveObject("Photo Fragment", id, false) {

}
Photograph::~Photograph() {
    for (size_t i = 0; i < Ids.size(); i++) {
        if (Ids.at(i) == getId()) {
            Ids.erase(Ids.begin() + i);
        }
    }
}