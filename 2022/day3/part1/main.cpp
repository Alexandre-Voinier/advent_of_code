#include <iostream>
#include <fstream>
#include <string>

#include "checkFile.h"

int main (int argc, char *argv[])
{  
  if (argc != 2)
  {
    std::cout << "Usage: day1 <inputFile>"  << std::endl;
    return 1;
  }

  if (checkFile(argv[1]))
  {

    std::ifstream file {argv[1]};
    if (!file) {
      std::cerr << "Error opening the file: " 
        << argv[1]
        << std::endl;
    }
    std::string s;
    int priorities {};
    while (getline(file, s))
    {
      std::size_t lenS {s.size()};
      std::string compartement1 {s.substr(0, lenS / 2)};
      std::string compartement2 {s.substr(lenS / 2, lenS / 2)};
      std::size_t index {std::string::npos};
      std::size_t pos {};
      while (index == std::string::npos)
      {
        index = compartement2.find_first_of(compartement1[pos++]);
      }
      char commonItem {compartement2[index]};
      if (commonItem >= 'A' && commonItem <= 'Z')
        priorities += commonItem - 'A' + 27;
      else
        priorities += commonItem - 'a' + 1;
    }
    std::cout << "Priorities: " << priorities << std::endl;
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE; 
}
