#include "BitcoinExchange.hpp"
#include <cstddef>
#include <cstring>
#include <iostream>

void checkNopen_File(std::string arg, std::ifstream &file) {
  if (arg.compare("data.csv") == 0) {
    file.open(arg, std::ifstream::in);
    if (file.fail()) {
      std::cerr << "Error: no data.csv in the current directory" << std::endl;
      exit(1);
    }
    return;
  }
  file.open(arg, std::ifstream::in);
  if (file.fail()) {
    std::cerr << "Error: argument file not found" << std::endl;
    exit(1);
  }
  return;
}

void date_value(char *dateValue) {
  if (strlen(dateValue) == 10) {
    char *date = strtok(dateValue, "-");
    std::cout << date << "\n";
    while (date != NULL) {
      date = strtok(NULL, "-");
      std::cout << date << "\n";
    }
  }
}

void tokenizizer(std::string &line) {
  char *cstr = new char[line.size() + 1];
  strcpy(cstr, line.c_str());
  char *tokn = strtok(cstr, " ");
  while (tokn != NULL) {
    // std::cout << tokn << "\n";
    tokn = strtok(NULL, " ");
    date_value(tokn);
  }
}

int parse_file(std::ifstream &file) {
  std::string line;
  while (std::getline(file, line)) {
    //    std::cout << line;
    tokenizizer(line);
  }
  return 1;
}
