#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl herl;

	if (argc == 2)
		herl.complain(argv[1]);
	else
		std::cout << "One single argument needed" << std::endl;
	return 0;
}