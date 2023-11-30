#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "checkFile.h"

bool mySort(int i, int j)
{
    return i > j;
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
        int tmpSum{};
        std::vector<int> calories{};
        while (getline(file, s))
        {
            if (s == "")
            {
                calories.push_back(tmpSum);
                tmpSum = 0;
            }
            else
            {
                tmpSum += stoi(s, nullptr);
            }
        }
        std::sort(calories.begin(), calories.end(), mySort);
        if (calories.size() > 2)
            std::cout << "Sum calories of first three: " << calories[0] + calories[1] + calories[2] << std::endl;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
