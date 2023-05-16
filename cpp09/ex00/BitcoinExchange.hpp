#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <limits>
#include <iostream>

void checkNopen_File(std::string arg, std::ifstream &file);
void parse_file(std::ifstream &file, std::map<std::string, std::string>& mapdb);
void populateMap(std::ifstream& file, std::map<std::string, std::string>& mapDb, char delim);
void errMsgs(int msg);
#endif
