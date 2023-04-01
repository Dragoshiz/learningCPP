#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>
#include <unistd.h>

template<class T>
class Array{
	public:
		Array():_array(new T[0]), _size(0){};

		Array(const unsigned int n){
			_array = new T[n];
			_size = n;
			for (size_t i=0; i < _size; i++)
				_array[i] = 0;
		};

		Array(Array const &obj){
			_array = new T[(obj._size)];
			for (size_t i = 0; i < obj._size; i++){
				_array[i] = obj._array[i];
			}
			_size = obj._size;
		};
		~Array(){
			std::cout <<"DESTRUCTOORR"<<std::endl;
			delete[] _array;
		};
		Array<T>& operator=(Array const &obj){
			if (this != &obj){
				_size = obj._size;
				if(_array != NULL)
					delete[] _array;
				_array = new T[_size];
				for(size_t i=0; i < obj._size; i++){
					_array[i] = obj._array[i];
				}
			}
			return *this;
		};
		T &operator[](unsigned int i)const{
			if(i >= _size || (_size == 0 && i == 0))
				throw(ArrayIndexOutOfBound());
			return _array[i];
		};
		class ArrayIndexOutOfBound: public std::exception{
			const char * what() const throw(){
				return "Array index out of bounds\n";
			};
		};
		int size(void)const{
			return _size;
		}
	private:
		T	*_array;
		size_t	_size;
};

#endif
