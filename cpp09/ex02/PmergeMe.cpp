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


std::string argv_to_string(int argc, char *argv[]){
	std::stringstream ss;
	std::string input;

	for (int i=1; i < argc; i++){
		ss << argv[i] << " ";
	}
	input = ss.str();

	return input;
}


void push_to_vector(std::vector<int>& d_vectr, int elem){
		d_vectr.push_back(elem);
}


bool check_tokn(const std::string token){
	for(std::string::const_iterator it = token.begin(); it != token.end(); ++it){
		if (!std::isdigit(*it))
			return false;
	}

	return true;
}


bool check_token_and_push(std::vector<int>& d_vectr, std::string& token){
	if (token.size() > 10) {
		errMsg(4);
		return false;
	}

	if (!check_tokn(token)) {
		errMsg(3);
		return false;
	}

	long element;
	std::stringstream token_stream(token);
	if (!(token_stream >> element)) {
		errMsg(3);
		return false;
	}

	if (element < 0) {
		errMsg(2);
		return false;
	}

	if (element > std::numeric_limits<int>::max()) {
		errMsg(4);
		return false;
	}

	push_to_vector(d_vectr, static_cast<int>(element));

	return true;
}


bool check_arg_content(std::vector<int>& d_vectr, const std::string& input) {
	std::stringstream input_stream(input);
	std::string token;

	while (input_stream >> token) {
		if (!check_token_and_push(d_vectr, token)) {
			return false;
		}
	}

	return true;
}


bool is_sorted(std::vector<int>& d_vectr){
	if (std::adjacent_find(d_vectr.begin(), d_vectr.end(), std::greater<int>()) == d_vectr.end()){
		errMsg(5);
		return true;
	}
	return false;
}


std::vector<std::pair<int, int > > vectr_pair_and_sort(std::vector<int>& d_vectr){
	std::vector<std::pair<int,int > > d_vectr_pair;

	for(size_t i=0; i < d_vectr.size(); i+=2){
		d_vectr_pair.push_back(std::make_pair(d_vectr[i], d_vectr[i + 1]));
	}

	//now sort pairs
	for (size_t i=0; i < d_vectr_pair.size(); i++){
		if(d_vectr_pair[i].first > d_vectr_pair[i].second)
			std::swap(d_vectr_pair[i].first, d_vectr_pair[i].second);
	}

	return d_vectr_pair;
} 

std::vector<std::pair<int, int > > pair_lesser_numbers(std::vector<std::pair<int, int > >& paired_sorted, size_t i){
	if (i < paired_sorted.size() - 1){
		if (paired_sorted[i].first > paired_sorted[i+1].first)
			std::swap(paired_sorted[i], paired_sorted[i+1]);
		pair_lesser_numbers(paired_sorted, i + 1);
	}
	return paired_sorted;
}


void push_small_nums_to_main_chain(std::vector<std::pair<int, int > >& paired_sorted_vectr, std::vector<int>& sorted){
	for (size_t i=0; i < paired_sorted_vectr.size(); i++){
		sorted.push_back(paired_sorted_vectr[i].first);
	}
}

int jacobsthal_nums(size_t n){
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal_nums(n - 1) + 2 * jacobsthal_nums(n - 2);
}

std::vector<int> push_large_nums(std::vector<std::pair<int, int > >& paired_sorted_vectr){
	std::vector<int> large_numbers_vectr;

	for (size_t i=0; i < paired_sorted_vectr.size(); i++){
		large_numbers_vectr.push_back(paired_sorted_vectr[i].second);
	}
	return large_numbers_vectr;
}

//this is just for debug
void go_tru_vectr(std::vector<std::pair<int, int > > & dvectr){
	for (size_t i=0; i < dvectr.size(); i++){
		std::cout << dvectr[i].first << " ";
		std::cout << dvectr[i].second << "\n";
	}
}


std::vector<int> recursive_merge_insert_alg(std::vector<int>& dvectr){
	std::vector<std::pair<int, int > > paired_sort_vectr;
	std::vector<int> main_chain;
	bool is_even = true;
	int straggler = 0;

	if (dvectr.size() > 1){

		if(dvectr.size() % 2 != 0){
			is_even = false;
			straggler = dvectr.back();
			dvectr.pop_back();
		}
		
		paired_sort_vectr = vectr_pair_and_sort(dvectr);
		go_tru_vectr(paired_sort_vectr);
		pair_lesser_numbers(paired_sort_vectr, 0);
		push_small_nums_to_main_chain(paired_sort_vectr, main_chain);
		for (size_t i=0; i<paired_sort_vectr.size(); i++){
			std::cout << "main chain: " << main_chain[i] << "\n";
		}
		go_tru_vectr(paired_sort_vectr);
		std::cout << jacobsthal_nums(5) << "\n";
		// push_small_nums_to_sorted(paired_sort_vectr, sorted);
		// large_numbers_vectr = push_large_nums(paired_sort_vectr);

		(void)is_even;
		(void)straggler;
		// if(!is_even)
		// 	large_numbers_vectr.push_back(straggler);
		
		// recursive_merge_insert_alg(large_numbers_vectr, sorted);
	}
	return main_chain;
}

