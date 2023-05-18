#include "PmergeMe.hpp"


void errMsg(int msg){
	switch (msg){
		case 1:
			std::cout << "Error: At least one argument is needed" << std::endl;
			break;
		case 2:
			std::cout << "Error: non positive int element passed in the argument" << std::endl;
			break;
		case 3:
			std::cout << "Error: non digit element was passed in the argument" << std::endl;
			break;
		case 4:
			std::cout << "Error: element bigger than an int found" << std::endl;
			break;
		case 5:
			std::cout << "Error: the elements are already sorted" << std::endl;
			break;
	}
}

bool compare_second(std::pair<int, int>&a , std::pair<int, int>&b){
	return a.second < b.second;
}

std::string argv_to_string(int argc, char *argv[]){
	std::string input;

	for (int i=1; i < argc; i++){
		input += argv[i];
		input += " ";
	}

	return input;
}

bool check_tokn(const std::string token){
	for(std::string::const_iterator it = token.begin(); it != token.end(); ++it){

		if (!std::isdigit(*it))
			return false;
	}

	return true;
}












int jacobsthal_nums(size_t n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal_nums(n - 1) + 2 * jacobsthal_nums(n - 2);
}











