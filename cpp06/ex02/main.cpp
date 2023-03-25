#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void){
	srand(time(NULL));
	switch (rand() % 3)
	{
		case 0:
			std::cout << "A was instantiated" << std::endl;
			return new A;
		case 1:
			std::cout << "B was instantiated" << std::endl;
			return new B;
		case 2:
			std::cout << "C was instantiated" << std::endl;
			return new C;
		default:
			break;
	}
	return NULL;
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Type not found" << std::endl;
}

void identify(Base &p){
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(std::exception &e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(std::exception &e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch(std::exception &e)
			{
				std::cout << "Type not found" << std::endl;
			}
		}
	}
}

int main(){
	Base *hello = generate();
	A a;
	Base &hello2= a;
	// Base &hello2= *hello;

	identify(hello);
	identify(&hello2);
	return 0;
}

