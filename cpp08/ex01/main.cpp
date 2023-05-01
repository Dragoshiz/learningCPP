#include "Span.hpp"

int main()
{
	{
		std::cout << "\n\n1st scope, we add numbers manually and copy operator and copy constructor\n";
		Span sp = Span(5);
		try{
			sp.addNumber(6);
			sp.addNumber(1);
			sp.addNumber(17);
			sp.addNumber(11);
			sp.addNumber(20);
		}
		catch(const std::exception &e){
			std::cerr << e.what() << "\n";
		}
		std::cout << "Elements of sp object\n"; 
		sp.showelem();
		std::cout << "shortestSpan: "; 
		std::cout << sp.shortestSpan() << "\n";
		std::cout << "longestSpan: "; 
		std::cout << sp.longestSpan() << std::endl;
		Span spn;
		spn = sp;
		std::cout << "Elements of copy operator spn object\n";
		spn.showelem();
		Span spn2 = Span(sp);
		std::cout << "Elements of copy constructor spn2 object\n";
		spn2.showelem();
	}

	{
		std::cout << "\n\n2nd scope, we add numbers using the addManyNumbers function\n";
		Span sp = Span(5);
		try{
			sp.addNumber(6);
			sp.addNumber(1);
		}
		catch(const std::exception &e){
			std::cerr << e.what() << "\n";
		}
		try{
			sp.addManyNumbers();
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << "Elements of sp object\n"; 
		sp.showelem();
		std::cout << "shortestSpan: "; 
		std::cout << sp.shortestSpan() << "\n";
		std::cout << "longestSpan: "; 
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "\n\n3rd scope, we show error handling: adding more than the size of vector\n";
		Span sp = Span(5);
		try{
			sp.addNumber(6);
			sp.addNumber(1);
			sp.addNumber(17);
			sp.addNumber(11);
			sp.addNumber(16);
			sp.addNumber(100);
		}
		catch(const std::exception &e){
			std::cerr << e.what() << "\n";
		}
		std::cout << "Elements of sp object\n"; 
		sp.showelem();
		std::cout << "shortestSpan: "; 
		std::cout << sp.shortestSpan() << "\n";
		std::cout << "longestSpan: "; 
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "\n\n4th scope, we show error handling: adding more using the addManyNumbers \n";
		Span sp;
		try
		{
			sp.addManyNumbers();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return 0;
}