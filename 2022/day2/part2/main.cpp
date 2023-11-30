#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "checkFile.h"

int roundScore(char elf, char player)
{
    if (elf == 'A')
    {
        if (player == 'X')
            return 3;
        else if (player == 'Y')
            return 4;
        else
            return 8;
    }
    else if (elf == 'B')
    {
        if (player == 'X')
            return 1;
        else if (player == 'Y')
            return 5;
        else
            return 9;
    }
    else
    {
        if (player == 'X')
            return 2;
        else if (player == 'Y')
            return 6;
        else
            return 7;
    }
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
        std::string s;
        int score{};
        while (getline(file, s))
        {
            if (s.size() > 2)
            {
                char elf{s[0]};
                char player{s[2]};
                score += roundScore(elf, player);
            }
        }
        std::cout << "Score: " << score << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
