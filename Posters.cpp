#include "Posters.h"
#include <algorithm>   // for std::remove
#include <iostream>
#include <string>
#include <vector>

std::string centerPostertext(const std::string& text, int width) {
    int padding = width - static_cast<int>(text.size());
    if (padding <= 0)
        return text.substr(0, width);

    int left = padding / 2;
    int right = padding - left;
    return std::string(left, ' ') + text + std::string(right, ' ');
}


std::vector<int> Posters::Ids;


Posters::Posters(std::string text, int X, int Y, int id)
    : InteractiveObject("Posters", id, true), text(std::move(text)) {
    Ids.push_back(id);
    setX(X);
    setY(Y);
    setSymbol(']');
}


Posters::~Posters() {
    int currentId = getId();
    Ids.erase(std::remove(Ids.begin(), Ids.end(), currentId), Ids.end());
}

void Posters::use() {
    const int width = 22;

    std::cout << "+----------------------+" << '\n';
    std::cout << "|" << centerPostertext("", width) << "|" << '\n';
    std::cout << "|" << centerPostertext("", width) << "|" << '\n';
    
    size_t start = 0;
    while (start < text.size()) {
        size_t end = text.find('\n', start);
        if (end == std::string::npos) end = text.size();
        std::string line = text.substr(start, end - start);
        std::cout << "|" << centerPostertext(line, width) << "|" << std::endl;
        start = end + 1;
    }

    std::cout << "|" << centerPostertext("", width) << "|" << '\n';
    std::cout << "|" << centerPostertext("", width) << "|" << '\n';
    std::cout << "+----------------------+" << '\n';
}