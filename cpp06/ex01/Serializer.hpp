#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>

typedef struct data
{
	int		num;
	char	lettr;
}Data;


class Serializer{
	public:
		Serializer();
		Serializer(Serializer const &);
		~Serializer();

		Serializer& operator=(Serializer const &);
		static uintptr_t serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};
#endif

