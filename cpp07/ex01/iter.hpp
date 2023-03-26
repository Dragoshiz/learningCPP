#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void iter(T *arr, T length, void (* func)(T&)){
	for (int i = 0; i < length; i++){
		func(arr[i]);
	};
}

template <typename T>
void increment(T& elem){
	elem++;
}

template <typename T>
void print(T &elem){
	std::cout << elem << std::endl;
}



#endif