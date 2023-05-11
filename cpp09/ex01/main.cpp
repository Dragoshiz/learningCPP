#include "RPN.hpp"

int main(int argc, char* argv[]){
	if (argc != 2){
		errMsgs(1);
		return 1;
	}
	std::stack<int> d_stack;
	if (!check_arg(argv[1])){
		return 1;
	}
	push_and_calc(d_stack, argv[1]);
	return 0;
}

