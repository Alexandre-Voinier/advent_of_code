#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "checkFile.h"
#include "parseCrates.h"
#include "printCrates.h"

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
        std::string topCrates{};
        std::vector<std::vector<char>> crates{parseCrates(file)};
        printCrates(crates);
        std::string line{};
        while (getline(file, line))
        {
            std::regex rgx{"move ([0-9]+) from ([0-9]) to ([0-9])"};
            std::smatch matches;

            if (std::regex_search(line, matches, rgx))
            {
                std::cout << "MATCHES: " << matches.size() << std::endl;
                if (matches.size() == 4)
                {
                    std::vector<int> operations{std::stoi(matches[1]), std::stoi(matches[2]) - 1,
                                                std::stoi(matches[3]) - 1};
                    for (std::size_t i = 0; i < operations.size(); i++)
                    {
                        std::cout << "Operations[" << i << "]: " << operations[i] << std::endl;
                    }
                    std::size_t sizeCratesFrom {crates[operations[1]].size()};
                    for (int i = 0; i < operations[0]; i++)
                    {
                        crates[operations[2]].push_back(crates[operations[1]][sizeCratesFrom - operations[0] + i]);
                    }
                    crates[operations[1]].resize(sizeCratesFrom - operations[0]);
                    printCrates(crates);
                }
            }
        }
        for (std::size_t i = 0; i < crates.size(); i++)
        {
            topCrates += crates[i].back();
        }
        std::cout << "Top Crates " << topCrates << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
