#include "Harl.hpp"

int main(void)
{
	Harl herl;

	herl.complain("DEBUG");
	herl.complain("INFO");
	herl.complain("WARNING");
	herl.complain("ERROR");
	herl.complain("Hello this is herl");
	return 0;
}
