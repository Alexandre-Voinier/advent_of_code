#include "parseCrates.h"

char parseCrate(std::string line, std::size_t &index)
{
    char crate = line[index + 1];
    index += 3;

    return crate;
}

std::vector<std::vector<char>> parseCrates(std::ifstream &file)
{
    std::string line{};
    getline(file, line);
    std::vector<std::vector<char>> crates{(line.size() - 3) / 4 + 1};
    while (line.size() > 1 && line[1] != 1)
    {
        std::size_t index{};
        while (index < line.size())
        {
            if (line[index] == '[')
            {
                crates[index / 4].insert(crates[index / 4].begin(), parseCrate(line, index));
            }
            else
            {
                index += 3;
            }
            index++;
        }
        getline(file, line);
    }
    return crates;
}