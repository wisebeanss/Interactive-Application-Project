#include "Posters.h"
#include <string>
#include <vector>
#include <iostream>

std::string centerDescription(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0) {
        return text.substr(0, width);
    }

    int left = padding / 2;
    int right = padding - left;

    return std::string(left, ' ') + text + std::string(right, ' ');
}


std::vector<int> Posters::Ids;

Posters::Posters(std::string text, int id)
    : InteractiveObject("Posters", id, true), text(std::move(text)) {
    Ids.push_back(id);
    setSymbol('^');
}

Posters::~Posters() {
    int currentId = getId();
    auto& ids = Ids;
  
    for (auto it = ids.rbegin(); it != ids.rend(); ++it) {
        if (*it == currentId) {
            ids.erase(std::next(it).base());
        }
    }
}

void Posters::use() {
    const int width = 22;

    std::cout << "+----------------------+" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription(text, width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "|" << centerDescription("", width) << "|" << std::endl;
    std::cout << "+----------------------+" << std::endl;
}