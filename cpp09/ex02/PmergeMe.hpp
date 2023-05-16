#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

void errMsg(int msg);
void go_tru_vectr(std::vector<std::pair<int, int > > & dvectr);
void sort_vectr_pair(std::vector<std::pair<int, int > >& paired_vectr);

bool check_arg_content(std::vector<int>& d_vectr, const std::string& input);
bool is_sorted(std::vector<int>& d_vectr);

std::vector<std::pair<int, int > > d_vectr_pair(std::vector<int>& d_vectr);
std::string argv_to_string(int argc, char *argv[]);
std::vector<int> recursive_merge_insert_alg(std::vector<int>& dvectr);

#endif