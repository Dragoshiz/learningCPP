#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
	if (argc < 2){
		errMsg(1);
		return 1;
	}

	int the_odd_one;
	std::string input = argv_to_string(argc, argv);
	std::vector<int> d_vectr;
	std::vector<int> sorted;
	std::vector<int> large_nums;
	if (!check_arg_content(d_vectr, input))
		return 1;
	
	if (is_sorted(d_vectr))
		return 1;

	// if (is_even(d_vectr)){
	// 	the_odd_one = d_vectr.back();
	// 	d_vectr.pop_back();
	// }

	// paired_vectr = d_vectr_pair(d_vectr);
	// go_tru_vectr(paired_vectr);
	std::cout << "now sorted \n";	

	// sort_vectr_pair(paired_vectr);
	recursive_merge_insert_alg(d_vectr);

	(void)the_odd_one;
	
	return 0;
}