#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	std::cout << "\x1b[32mScalarConverter default constructor called\033[0m" << std::endl;
}

ScalarConverter::~ScalarConverter(){
	std::cout << "\x1b[31mScalarConverter destructor called\033[0m" << std::endl;
}

size_t countDecimals(const char* arg){
	std::string str(arg);
	size_t decimPos = str.find(".");
	if(decimPos == std::string::npos)
		return 0;
	return (str.size() - decimPos - 1);
}

bool isFloat(const char *arg){
	std::string str(arg);
	if(str[str.length()- 1] == 'f')
		return true;
	return false;
}

bool isValidInt(const char *arg){
	std::string str(arg);
	if(str.length() > std::numeric_limits<int>::digits10 + 1)
		return false;
	int atoited = atoi(arg);
	if(atoited == 0 && str != "0")
		return false;
	return true;
}


void ScalarConverter::convert(const char* arg){
	int dec = 0;
	if (isValidInt(arg))
		dec = atoi(arg);
	char characher = dec;
	float ff = static_cast<float>(atof(arg));
	double doubl = (atof(arg));
	size_t dot = countDecimals(arg);

	if (dec > 31 && dec < 127){ //this goes at the bottom;
		std::cout << "char: " << characher << "\n";
	}
	else{
		std::cout << "char: Non displayable" << "\n";
	}
	std::cout <<"int: " << dec << std::endl;
	std::cout << "float: "<< std::fixed << std::setprecision(dot) << ff<< "f" << "\n";
	std::cout << "double: " << std::fixed <<std::setprecision(dot)<< doubl<< std::endl;

}

