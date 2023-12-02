#include <filesystem>

#include "checkFile.h"

bool checkFile(std::string path)
{
    std::filesystem::path filepath{path};
    if (std::filesystem::exists(filepath))
    {
        if (std::filesystem::is_regular_file(filepath))
        {
            return true;
        }
    }
    return false;
}
