#include "BitcoinExchange.hpp"

std::ifstream checkNopen_File(std::string arg){
	if (arg.compare("data.csv") == 0){
		std::ifstream db_file;
		db_file.open("data.csv");
		if (db_file.fail()){
			std::cerr << "Error: no data.csv in the current directory" << std::endl;
			exit(1);
		}
		return db_file;
	}
	std::ifstream in_file;
	in_file.open(arg);
	if (in_file.fail()){
		std::cerr << "Error: argument file not found" << std::endl;
		exit(1);
	}
	return in_file;
}

int parse_file(std::ifstream& file){
	std::string line;
	while(std::getline(file, line)){
		std::cout << line;
	}
	return 1;
}