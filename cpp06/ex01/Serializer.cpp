#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout << "\x1b[32mSerializer default constructor called\033[0m" << std::endl;
}

Serializer::Serializer(Serializer const &obj){
	std::cout << "\x1b[33mSerializer copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Serializer::~Serializer(){
	std::cout << "\x1b[31mSerializer destructor called\033[0m" << std::endl;
}

Serializer& Serializer::operator=(Serializer const &obj){
	std::cout << "\x1b[33mSerializer copy assignment operator called\033[0m" << std::endl;
	*this = obj;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}

