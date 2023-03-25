#include "Serializer.hpp"

int main(){
	Data data = {1, 'a'};
	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << &ptr <<"\n" << &data<< "\n";
	Data* hello;
	hello = Serializer::deserialize(ptr); 
	std::cout << &ptr <<"\n" << hello << " "<< hello->lettr<< "\n";
	return 0;
}

