#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <limits>
#include <cstddef>
#include <cstring>
#include <iostream>

void checkNopen_File(std::string arg, std::ifstream &file);
int parse_file(std::ifstream &file);
void populateMapDb(std::ifstream& file, std::map<std::string, std::string>& mapDb);

#endif
