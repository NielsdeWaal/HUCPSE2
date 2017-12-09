#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>
#include <ctype.h>

auto countCharacters(const std::vector<char>& countVector) {
    std::map<char, int> resultMap;
    for(auto character = 0x61; character <= 0x7A; ++character) {
        resultMap[character] = std::count(countVector.begin(), countVector.end(), character);
    }
    return resultMap;
}

auto fillVector(const auto& filename, std::vector<char>& destVector) {
    std::ifstream file("bible.txt");

    file >> std::noskipws;

    std::copy(std::istream_iterator<char>(file), 
              std::istream_iterator<char>(),
              std::back_inserter(destVector));
}

auto fillWordVector(const auto& filename, std::vector<std::string>& destVector) {
    std::ifstream file("bible.txt");

    std::copy(std::istream_iterator<std::string>(file),
              std::istream_iterator<std::string>(),
              std::back_inserter(destVector));
}

int main() {
    constexpr const auto filename = "bible.txt";
    std::vector<char> characterVector;
    std::vector<std::string> wordVector;

    fillVector(filename, characterVector);
    fillWordVector(filename, wordVector);

    auto lines = std::count(characterVector.begin(), characterVector.end(), '\n');
    auto alphabeticCharacters = std::count_if(characterVector.begin(),
                                              characterVector.end(),
                                              [](char c){return /*('a' <= c <= 'z')||('A' <= c <= 'Z');*/ isalpha(c);});
    std::transform(characterVector.begin(), characterVector.end(), characterVector.begin(),
                    [](char c) -> char {return std::tolower(c);});

    auto characterCount = countCharacters(characterVector);
    std::map<int, char> countOrderMap;

    for (auto&& [key, value] : characterCount) {
        countOrderMap[value] = key;
    }

    try {
        std::cout << "Vector size: " << characterVector.size() << "\n";
        std::cout << "Amount of lines: " << lines << "\n";
        std::cout << "Amount of characters: " << alphabeticCharacters << "\n";
        std::cout << "Converting characters to lowercase" << "\n";

        for (auto&& [key,value] : characterCount) {
            std::cout << "Char: " << key << ", value: " << value << "\n";
        }


        for (auto&& [key,value] : countOrderMap) {
            std::cout << "Char: " << key << ", value: " << value << "\n";
        }

    } catch(...) {
        std::cout << "Data incorrect" << "\n";
    }
}
