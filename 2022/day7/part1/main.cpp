#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Directory.hpp"
#include "File.hpp"
#include "checkFile.h"
#include "parser.hpp"

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
        std::shared_ptr<Directory> rootDir{parser(file)};
        rootDir->updateSize();
        rootDir->tree();
        std::cout << "SOLUTION: " << rootDir->getSolution() << std::endl;
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
