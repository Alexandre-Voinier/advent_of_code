#include "checkFile.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::size_t findMarker(std::string &str)
{
    std::size_t index{};
    for (; index < str.size() - 13; index++)
    {
        std::string sub = str.substr(index, 14);
        std::sort(sub.begin(), sub.end());
        bool isMarker{true};
        for (std::size_t i = 0; i < sub.size() - 1; i++)
        {
            if (sub[i] == sub[i + 1])
            {
                isMarker = false;
            }
        }
        if (isMarker)
        {
            break;
        }
    }
    return index;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: day1 <inputFile>" << std::endl;
        return 1;
    }

    if (checkFile(argv[1]))
    {

        std::ifstream file{argv[1]};
        if (!file)
        {
            std::cerr << "Error opening the file: " << argv[1] << std::endl;
        }
        std::string datastream{};
        std::string line{};
        while (getline(file, line))
        {
            datastream += line;
        }
        std::cout << "Character before marker " << findMarker(datastream) + 14 << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
