#include "Span.hpp"

// int main(){
// 	Span spanning(5);
// 	spanning.addNumber(5);
// 	spanning.addNumber(1);
// 	spanning.addNumber(7);
// 	spanning.addNumber(-5);
// 	spanning.addNumber(-5);
// 	// spanning.shortestSpan();
// 	// spanning.longestSpan();
// 	std::cout << spanning.shortestSpan() << "\n";
// 	std::cout << spanning.longestSpan() << "\n";
// }

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
// sp.addManyNumbers();
// sp.showelem();

std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
return 0;
}