#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
	if (argc < 2){
		errMsg(1);
		return 1;
	}

	std::string input = argv_to_string(argc, argv);
	std::vector<int> d_vectr;
	std::deque<int> d_deque;
	
	if(!check_arg_content<std::deque<int > >(d_deque, input))
		return 1;

	if(is_sorted<std::deque<int > >(d_deque))
		return 1;

	if (!check_arg_content<std::vector<int > >(d_vectr, input))
		return 1;

	if (is_sorted<std::vector<int > >(d_vectr))
		return 1;
		
	// merge_insert_alg<std::vector<int>, std::vector<std::pair<int, int > > >(d_vectr);
	// merge_insert_alg<std::deque<int>, std::deque<std::pair<int, int > > >(d_deque);
	
	return 0;
}