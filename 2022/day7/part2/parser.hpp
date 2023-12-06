#pragma once // PARSER_HPP

#include <fstream>
#include <memory>

#include "Directory.hpp"

std::shared_ptr<Directory> parser(std::ifstream &file);