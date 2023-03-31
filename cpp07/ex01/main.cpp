#include "iter.hpp"

int main(){
	{
		int arr[10] = {1,2,3,4,5,6,7,8,9,10};

		::iter(arr, 10, increment<int>);
		::iter(arr, 10, print<int>);
		std::cout << "\n" << std::endl;
	}
	{
		double arr[10] = {1.1,2.3,3.5,4.6,5.7,6.8,7.9,8.1,9.2,10.3};

		::iter(arr, 10, increment<double>);
		::iter(arr, 10, print<double>);
		std::cout << "\n" << std::endl;
	}
	{
		char arr[10] = {'1','2','3','4','5','6','7','8','9','0'};

		::iter(arr, 10, increment<char>);
		::iter(arr, 10, print<char>);
		std::cout << "\n" << std::endl;
	}
}
