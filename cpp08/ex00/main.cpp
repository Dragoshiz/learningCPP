#include "easyfind.hpp"

int main(){
	{
		int d_values[] = {0, 5, 2, 4, 3, 7, 6, 8, 9, 1};
		std::vector<int> d_array(d_values, d_values + sizeof(d_values)/sizeof(int));

		std::cout << easyFind(d_array, 6) << "\n";

		try
		{
			std::cout << easyFind(d_array, 10) << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		char ch_values[] = {'z', 'e', 's', 'h', 'i', 't', 'y', 'd', 'a', 'y'};
		std::vector<char> ch_arr(ch_values, ch_values + sizeof(ch_values)/sizeof(char));
		
		std::cout << static_cast<char>(easyFind(ch_arr, 't')) << "\n";

		try
		{
			std::cout << static_cast<char>(easyFind(ch_arr, 'q')) << "\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
