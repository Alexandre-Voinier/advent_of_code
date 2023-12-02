#include <iostream>

#include "printCrates.h"

void printCrates(std::vector<std::vector<char>> &crates)
{
    for (std::size_t i = 0; i < crates.size(); i++)
    {
        std::vector<char> crate = crates[i];
        std::cout << i << '[';
        for (std::size_t j = 0; j < crate.size(); j++)
        {
            if (j == 0)
            {
                std::cout << crate[j];
            }
            else
            {
                std::cout << ", " << crate[j];
            }
        }
        std::cout << ']' << std::endl;
    }
}