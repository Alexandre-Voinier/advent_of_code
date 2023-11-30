#include <fstream>
#include <iostream>
#include <string>

#include "checkFile.h"

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
        std::string elf1{};
        std::string elf2{};
        std::string elf3{};
        int priorities{};
        while (getline(file, elf1))
        {
            getline(file, elf2);
            getline(file, elf3);
            std::cout << "ELF 1: " << elf1 << std::endl;
            std::cout << "ELF 2: " << elf2 << std::endl;
            std::cout << "ELF 3: " << elf3 << std::endl;
            std::size_t index{std::string::npos};
            std::size_t index2{std::string::npos};
            std::size_t pos{};
            while (index == std::string::npos || index2 == std::string::npos)
            {
                index = elf2.find_first_of(elf1[pos]);
                index2 = elf3.find_first_of(elf1[pos++]);
            }
            std::cout << "INDEX1: " << index << "\nINDEX2: " << index2 << std::endl;
            char commonItem{elf2[index]};
            std::cout << "Badge: " << commonItem << std::endl;
            if (commonItem >= 'A' && commonItem <= 'Z')
                priorities += commonItem - 'A' + 27;
            else
                priorities += commonItem - 'a' + 1;
        }
        std::cout << "Priorities: " << priorities << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
