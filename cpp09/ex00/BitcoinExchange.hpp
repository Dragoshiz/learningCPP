#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void checkNopen_File(std::string arg, std::ifstream &file);
int parse_file(std::ifstream &file);

#endif
