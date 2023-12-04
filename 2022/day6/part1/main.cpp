#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "checkFile.h"

std::size_t findMarker(std::string &str)
{
    std::size_t index {};
    for (; index < str.size() - 3; index++)
    {
        char a{str[index]};
        char b{str[index + 1]};
        char c{str[index + 2]};
        char d{str[index + 3]};

        if (a != b && a != c && a != d && b != c && b != d && c != d)
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
        std::cout << "Character before marker " << findMarker(datastream) + 4 << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
