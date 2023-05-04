#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>

std::ifstream checkNopen_File(std::string arg);
int parse_file(const std::ifstream& file);


#endif

