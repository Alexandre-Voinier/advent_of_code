#include <iostream>

#include "Directory.hpp"

Directory::Directory(std::string name) : m_name(name){};

Directory::~Directory()
{
    std::cout << "Destructor of directory: " << m_name << std::endl;
}

void Directory::addFile(std::string filename, unsigned long fileSize)
{
    m_files.push_back(std::make_unique<File>(filename, fileSize));
}

void Directory::addSubDirectory(std::string directoryName)
{
    m_subDirectories.push_back(std::make_shared<Directory>(directoryName));
}

void Directory::updateSize()
{
    for (auto &file : m_files)
    {
        m_size += file->getSize();
    }

    for (auto &subDirectory : m_subDirectories)
    {
        subDirectory->updateSize();
        m_size += subDirectory->m_size;
    }
}

std::shared_ptr<Directory> Directory::goInto(std::string subDirectoryName) const
{
    for (auto subDirectory : m_subDirectories)
    {
        if (subDirectory->m_name == subDirectoryName)
        {
            return subDirectory;
        }
    }
    return nullptr;
}

void Directory::tree(unsigned deep) const
{
    for (unsigned i = 0; i < deep * 4; i++)
    {
        std::cout << " ";
    }
    std::cout << "- " << m_name << " (dir, size: " << m_size << ")" << std::endl;

    for (auto &subDirectory : m_subDirectories)
    {
        subDirectory->tree(deep + 1);
    }

    for (auto &file : m_files)
    {
        file->display(deep + 1);
    }
}

unsigned long Directory::getSolution(unsigned long solution, unsigned long spaceNeeded) const
{
    if (m_size >= spaceNeeded && m_size < solution)
    {
        solution = m_size;
    }
    for (auto subDirectory : m_subDirectories)
    {
        solution = subDirectory->getSolution(solution);
    }
    return solution;
}