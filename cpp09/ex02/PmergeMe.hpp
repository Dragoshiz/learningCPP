#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <limits>
#include <string>
#include <deque>
#include <vector>
#include <sstream>
#include <algorithm>
#include <typeinfo>
#include <sys/time.h>
#include <string.h>
#include <iomanip>

typedef struct s_struct{
	timeval start,end;
}t_struct;

void errMsg(int msg);
std::string argv_to_string(int argc, char *argv[]);
std::string argv_to_string(int argc, char *argv[]);
int jacobsthal_nums(size_t n);

bool check_tokn(const std::string token);
bool compare_second(std::pair<int, int>&a , std::pair<int, int>&b);

template<typename Container>
void print_container(Container& d_container){
	for (size_t i=0; i < d_container.size(); i++){
		if (i < 5)
			std::cout << d_container[i] << " ";
		else{
			std::cout << "[...]";
			break;
		}
	}
}

template<typename Container>
void push_to_vector(Container& d_container, int elem){
		d_container.push_back(elem);
}

template<typename Container>
bool check_token_and_push(Container& d_container, std::string& token){
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
	
	push_to_vector(d_container, static_cast<int>(element));
	return true;
}

template<typename Container>
bool check_arg_content(Container& d_container, const std::string& input, t_struct *time) {
	std::stringstream input_stream(input);
	std::string token;

	gettimeofday(&time->start, NULL);
	while (input_stream >> token) {

		if (!check_token_and_push(d_container, token)) {
			return false;
		}
	}
	return true;
}

template<typename Container>
bool is_sorted(Container& d_container){
	if (std::adjacent_find(d_container.begin(), d_container.end(), std::greater<int>()) == d_container.end()){
		errMsg(5);
		return true;
	}
	return false;
}

//makes paires and sort them
template<typename Container, typename PairContainer>
PairContainer vectr_pair_and_sort(Container& d_container, int straggler, bool is_even){
	PairContainer pair_container;

	for(size_t i=0; i < d_container.size(); i+=2){
		pair_container.push_back(std::make_pair(d_container[i], d_container[i + 1]));
	}
	//put straggler in if vector is odd
	if (!is_even)
		pair_container.push_back(std::make_pair(-1, straggler));

	//now sort pairs
	for (size_t i=0; i < pair_container.size(); i++){

		if(pair_container[i].first > pair_container[i].second)
			std::swap(pair_container[i].first, pair_container[i].second);
	}

	//sort the large numbers of the pairs
	std::sort(pair_container.begin(), pair_container.end(), compare_second);
	return pair_container;
} 


template<typename Container, typename PairContainer>
void push_larger_nums_to_main_chain(PairContainer& paired_sorted_container, Container& sorted){
	for (size_t i=0; i < paired_sorted_container.size(); i++){
		sorted.push_back(paired_sorted_container[i].second);
	}
}


template<typename Container, typename PairContainer>
Container push_large_nums(PairContainer& paired_sorted_container){
	Container large_numbers_vectr;

	for (size_t i=0; i < paired_sorted_container.size(); i++){
		large_numbers_vectr.push_back(paired_sorted_container[i].second);
	}
	return large_numbers_vectr;
}


template<typename Container, typename PairContainer>
void insert_to_main_chain(PairContainer& paired_container, Container& s_main_chain, int straggler){

	if (straggler != s_main_chain[0]){
		for(size_t i=0; i < paired_container.size(); i++){

			if (s_main_chain[0] == paired_container[i].second){
				s_main_chain.insert(s_main_chain.begin(), paired_container[i].first);
			}
		}
	}

}

template<typename Container>
int binary_search_insertion(Container& s_main_list, int value){
	int low = 0;
	int high = static_cast<int>(s_main_list.size() - 1);

 	while(low <= high){
		int middle = (low + high) / 2;
		if (value < s_main_list[middle])
			high = middle - 1;
		else
			low = middle + 1; 
	}
	return low;
}


template<typename Container, typename PairContainer>
void make_jacobs_sequence(PairContainer& paired_container, Container& jacobs_num){
	int i = 3;
	jacobs_num.push_back(1);

	//loop goes until the size of the paired_vector is not found in the jacobs_num vector
	while(std::find(jacobs_num.begin(), jacobs_num.end(), paired_container.size()) == jacobs_num.end()){
		int num = jacobsthal_nums(i++);
		jacobs_num.push_back(num);

		//looping until there is no occurrance of the num in the jacobs_num
		while (std::find(jacobs_num.begin(), jacobs_num.end(), --num) == jacobs_num.end())
		{
			jacobs_num.push_back(num);
		}
	}
}


template<typename Container, typename PairContainer>
Container push_2_chain(PairContainer& paired_container, Container& jacobs_nums){
	Container main_chain;

	//pushing large numbers of the pairs to the main_chain;
	for (size_t i=0; i < paired_container.size(); i++){
		main_chain.push_back(paired_container[i].second);
	}

	//iterating thorugh the jacobs_nums and finding where to insert the number
	for(size_t i=0; i < jacobs_nums.size(); i++){
		if((jacobs_nums[i] - 1) < static_cast<int>(paired_container.size())){
			if(paired_container[jacobs_nums[i] - 1].first == - 1)
				continue;
			int index = binary_search_insertion(main_chain, paired_container[jacobs_nums[i] - 1].first);
			main_chain.insert(main_chain.begin() + index, paired_container[jacobs_nums[i] - 1].first);
		}
	}
	return main_chain;
}


template<typename Container>
void print_infos(Container& container, s_struct *time){
	std::string container_name;

	long time_us= (time->end.tv_sec- time->start.tv_sec) * 1000000 + (time->end.tv_usec - time->start.tv_usec);
	double time_s = static_cast<double>(time_us);
	if (strcmp(typeid(Container).name(),"St6vectorIiSaIiEE") == 0)
		container_name = "std::vector";
	else
		container_name = "std::deque";
	std::cout << "Time to process a range of " << container.size() << " elements with " << container_name << ": " << time_s << " us" << std::endl;
}


template<typename Container, typename PairContainer>
Container merge_insert_alg(Container& d_container, t_struct *time){
	PairContainer paired_sort_vectr;
	Container s_main_chain;
	Container jacobs_nums;
	bool is_even = true;
	int straggler = 0;

	if (d_container.size() > 1){

		if(d_container.size() % 2 != 0){
			is_even = false;
			straggler = d_container.back();
			d_container.pop_back();
		}

		paired_sort_vectr = vectr_pair_and_sort<Container, PairContainer>(d_container, straggler, is_even);
		make_jacobs_sequence<Container>(paired_sort_vectr, jacobs_nums);
		s_main_chain = push_2_chain<Container, PairContainer>(paired_sort_vectr, jacobs_nums);
		gettimeofday(&time->end,NULL);
	}
	return s_main_chain;
}

#endif
