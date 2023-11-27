#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
    int tmpSum {};
    int maxSum {};
    while (getline(file, s))
    {
      if (s == "")
      {
        if (tmpSum > maxSum)
        {
          maxSum = tmpSum;
        }
        tmpSum = 0;
      }
      else
      {
        tmpSum += stoi(s, nullptr);

      }
    }
    std::cout << "Max calories: " << maxSum << std::endl;
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE; 
}
