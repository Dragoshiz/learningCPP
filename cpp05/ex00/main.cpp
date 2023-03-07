#include "Bureaucrat.hpp"

int main(){
	Bureaucrat bureau;
	std::cout << bureau;
	Bureaucrat bureau2(bureau);
	std::cout << bureau2;
	try
	{
		Bureaucrat bureauMain("Retard", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i=0; i < 149; i++)
		bureau.increment();
	try{
		bureau.increment();
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
	// bureau2.decrement();
	try
	{
		bureau2.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
