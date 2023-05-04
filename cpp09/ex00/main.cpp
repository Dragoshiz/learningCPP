#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
	(void)argv;
	if (argc != 2){
		std::cout << "Error: only one argument needed.\n";
		return 1;
	}
	std::string arg = argv[1];
	parse_file(checkNopen_File(arg));
	return 0;
}
