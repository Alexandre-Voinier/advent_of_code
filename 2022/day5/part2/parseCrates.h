#ifndef PARSE_CRATES_H
#define PARSE_CRATES_H

#include <fstream>
#include <string>
#include <vector>

char parseCrate(std::string line, std::size_t &index);

std::vector<std::vector<char>> parseCrates(std::ifstream &file);

#endif /* PARSE_CRATES_H */