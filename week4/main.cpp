#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

auto countChar(const std::vector<char>& countVector, const char& character) {
    std::map<char, int> resultMap;
    resultMap[character] = std::count(countVector.begin(), countVector.end(), character);
    return resultMap;
}

auto countCharacters(const std::vector<char>& countVector) {
    auto std::vector<std::map> resultVector;
    for(auto character = 0x61; character <= 0x7A; ++character) {
        resultVector.push_back(countChar(countVector, character));
    }
    return resultVector;
}

auto fillVector(const auto& filename, std::vector<char>& destVector) {
    std::ifstream file("bible.txt");

    file >> std::noskipws;

    std::copy(std::istream_iterator<char>(file), 
              std::istream_iterator<char>(),
              std::back_inserter(destVector));
}

int main() {
    constexpr const auto filename = "bible.txt";
    std::vector<char> characterVector;

    fillVector(filename, characterVector);
    auto lines = std::count(characterVector.begin(), characterVector.end(), '\n');
    auto alphabeticCharacters = std::count_if(characterVector.begin(),
                                              characterVector.end(),
                                              [](char c){return ('a' <= c <= 'z')||('A' <= c <= 'Z');});
    std::transform(characterVector.begin(), characterVector.end(), characterVector.begin(),
                    [](char c) -> char {return std::tolower(c);});

    auto characterCount = countCharacters(characterVector);

    try {
        std::cout << "Vector size: " << characterVector.size() << "\n";
        std::cout << "Amount of lines: " << lines << "\n";
        std::cout << "Amount of characters: " << alphabeticCharacters << "\n";
        std::cout << "Converting characters to lowercase" << "\n";

        for(auto p : characterCount) {
            std::cout << p

    } catch(...) {
        std::cout << "Data incorrect" << "\n";
    }
}
