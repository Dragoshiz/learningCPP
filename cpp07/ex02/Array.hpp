#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template<class T>
class Array{
	public:
		Array(){
			_array = new T[0];
			_size = 0;
		};
		Array(unsigned int n){
			_array = new T[n];
			_size = n;
		};
		Array(Array const &obj){
			_array = new T[(obj._size)];
			for (int i = 0; i < obj._size; i++){
				_array[i] = obj._array[i];
			}
			_size = obj._size;
		};
		int size(void)const{
			return _size;
		}
		~Array(){
			// delete[] _array;
		};
		Array<T>& operator=(Array const &obj){
			if (this != &obj){
				_array = new T[_size];
				for(int i=0; i < obj._size; i++){
					_array[i] = obj._array[i];
				}
				_size = obj._size;
			}
			return *this;
		};
		T &operator[](int i){
			if(i > _size || i < 0)
				throw(ArrayIndexOutOfBound());
			return _array[i]; 
		}
		class ArrayIndexOutOfBound: public std::exception{
			const char * what() const throw(){
				return "Array index out of bounds";
			};
		};
	private:
		T		*_array;
		int	_size;
};	
#endif

