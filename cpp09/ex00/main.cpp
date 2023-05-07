#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    errMsgs(4);
    return 1;
  }
  std::string arg = argv[1];
  std::ifstream db;
  std::ifstream file;
  std::map<std::string, std::string> mapdb;
  checkNopen_File(std::string("data.csv"), db);
  checkNopen_File(arg, file);
  populateMap(db, mapdb, ',');
  // std::map<std::string, std::string>::iterator it;
  // for (it = mapdb.begin(); it != mapdb.end(); ++it) {
  //       std::cout << it->first << ": " << it->second << std::endl;
  //   }
  parse_file(file, mapdb);
  return 0;
}
