#pragma once // DIRECTORY_HPP

#include <memory>
#include <string>
#include <vector>

#include "File.hpp"

class Directory
{
public:
    Directory(std::string name);
    ~Directory();

    void addFile(std::string filename, unsigned long fileSize);
    void addSubDirectory(std::string directoryName);
    
    void updateSize();

    unsigned long getSolution(unsigned long solution = 70'000'000, unsigned long spaceNeeded = 389'918) const;

    std::shared_ptr<Directory> goInto(std::string subDirectoryName) const;

    void tree(unsigned deep = 0) const;
private:
    std::string m_name {};
    unsigned long m_size {};
    std::vector<std::shared_ptr<Directory>> m_subDirectories {};
    std::vector<std::unique_ptr<File>> m_files {};
};