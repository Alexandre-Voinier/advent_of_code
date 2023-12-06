#include <iostream>
#include <string>

#include "parser.hpp"

std::shared_ptr<Directory> parser(std::ifstream &file)
{
    std::shared_ptr<Directory> rootDir{std::make_shared<Directory>("/")};
    std::vector<std::shared_ptr<Directory>> path{rootDir};

    std::string line{};
    while (getline(file, line))
    {
        if (path.back() == nullptr)
        {
            std::cout << "An error occur while parsing" << std::endl;
            break;
        }

        if (line.size() > 3 && line.substr(0, 3) == "dir")
        {
            path.back()->addSubDirectory(line.substr(4));
        }
        else if (line.size() > 1 && line[0] >= '1' && line[0] <= '9')
        {
            std::size_t whitespaceIndex = line.find(' ');
            unsigned long fileSize{stoul(line.substr(0, whitespaceIndex))};
            std::string filename{line.substr(whitespaceIndex + 1)};
            path.back()->addFile(filename, fileSize);
        }
        else if (line.size() > 4 && line.substr(0, 4) == "$ cd")
        {
            std::string directoryName{line.substr(5)};
            if (directoryName == "..")
            {
                path.pop_back();
            }
            else if (directoryName != "/")
            {
                path.push_back(path.back()->goInto(directoryName));
            }
        }
    }
    return rootDir;
}