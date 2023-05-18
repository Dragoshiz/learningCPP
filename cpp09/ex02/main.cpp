#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
	if (argc < 2){
		errMsg(1);
		return 1;
	}
	t_struct time;
	std::string input = argv_to_string(argc, argv);
	//vector just to print stuff so that the other 2 do only the sorting part and final time print
	std::vector<int> to_print;
	std::vector<int> d_vectr;
	std::deque<int> d_deque;

	if(!check_arg_content<std::vector<int > >(to_print, input, &time))
		return 1;

	if(is_sorted<std::vector<int > >(to_print))
		return 1;
	
	std::cout << "Before: ";
	print_container(to_print);
	std::cout << "\n";
	merge_insert_alg<std::vector<int>, std::vector<std::pair<int, int > > >(to_print, &time);
	std::cout << "After: ";
	print_container(to_print);
	std::cout << "\n";
	
	if(!check_arg_content<std::deque<int > >(d_deque, input, &time))
		return 1;

	if(is_sorted<std::deque<int > >(d_deque))
		return 1;
	
	merge_insert_alg<std::deque<int>, std::deque<std::pair<int, int > > >(d_deque, &time);
	print_infos<std::deque<int > >(d_deque, &time);

	
	if (!check_arg_content<std::vector<int > >(d_vectr, input, &time))
		return 1;

	if (is_sorted<std::vector<int > >(d_vectr))
		return 1;

	merge_insert_alg<std::vector<int>, std::vector<std::pair<int, int > > >(d_vectr, &time);
	print_infos<std::vector<int > >(d_vectr, &time);
	return 0;
}