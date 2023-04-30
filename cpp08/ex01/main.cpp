#include "Span.hpp"

int main()
{
Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(1);
// sp.addNumber(17);
// sp.addNumber(11);
sp.addManyNumbers();
// std::cout << "\n";
sp.showelem();

Span spanner(3);
// spanner = sp;
spanner.showelem();
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;
return 0;
}