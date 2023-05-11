#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <cstring>


void errMsgs(int msg);
bool check_arg(char *argv);
void push_and_calc(std::stack<int>& d_stack, char *argv);

#endif
