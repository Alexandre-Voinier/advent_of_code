#include <iostream>

#include "File.hpp"

File::File(std::string name, unsigned long size) : m_name(name), m_size(size){};

File::~File()
{
    std::cout << "Destructor of file " << m_name << std::endl;
}

void File::display(unsigned deep) const
{
    for (unsigned i = 0; i < deep * 4; i++)
    {
        std::cout << " ";
    }
    std::cout << "- " << m_name << " (file, size: " << m_size << ")" << std::endl;
}

unsigned long File::getSize() const
{
    return m_size;
}