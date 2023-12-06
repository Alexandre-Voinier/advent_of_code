#pragma once // FILE_HPP

#include<string>

class File
{
public:
    File(std::string name, unsigned long size);
    ~File();
    
    void display(unsigned deep) const;
    unsigned long getSize() const;
private:
    std::string m_name {};
    unsigned long m_size {};
};