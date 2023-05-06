#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Error: only one argument needed.\n";
    return 1;
  }
  std::string arg = argv[1];
  std::ifstream file;
  checkNopen_File(arg, file);
  parse_file(file);
  return 0;
}
