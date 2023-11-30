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
    int uselessPairs {};
    while (getline(file, s))
    {
      // Cutting
      std::size_t index {};
      std::cout << "Pairs: " << s << std::endl;
      int range1A = std::stoi(s, &index);
      std::string pairsLeft {s.substr(index + 1)};
      int range1B = std::stoi(pairsLeft, &index);
      pairsLeft = pairsLeft.substr(index + 1);
      int range2A = std::stoi(pairsLeft, &index);
      pairsLeft = pairsLeft.substr(index + 1);
      int range2B = std::stoi(pairsLeft, &index);

      // Test
      if ((range1A <= range2A && range2B <= range1B) || 
        (range2A <= range1A && range1B <= range2B))
      {
        uselessPairs++;
      }
    }
    std::cout << "Useless pairs: " << uselessPairs << std::endl;
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE; 
}
