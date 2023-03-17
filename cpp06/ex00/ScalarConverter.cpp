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
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && arg[i] != '\0' && i == 0)
			i++;
		if (isdigit(arg[i]) == 0)
		{
			if (arg[i] == 'f' && arg[i + 1] == '\0' && i != 0)
				continue ;
			return false;
		}
	}
	return true;
}

int getInt(const char *arg){
	
}

bool	scientificNotation(const char* arg){
	std::string args = arg;
	std::string arr[8] = {"inf","inff","nan","nanf","-inf","-inff", "+inf", "+inff"};
	int i = 0;
	while (i < 8 && args.compare(arr[i]) != 0)
		i++;
	if (i < 8)
	{
		std::cout << "float: " << ((i % 2 ==0)? arr[i + 1] : arr[i]) << "\n";
		std::cout << "double: " << ((i % 2 ==0)? arr[i] : arr[i - 1]) << std::endl;
		return true;
	}
	return false;
}

// bool isNum(std::string const &str)
// {
// 	auto it = str.begin();
// 	while (it != str.end() && std::isdigit(*it)) {
// 		it++;
// 	}
// 	return !str.empty() && it == str.end();
// }

void isChar(const char* arg){
	if(isValidInt(arg)){
		int num = atoi(arg);
		if (num >= 32 && num < 127)
			std::cout << "char: " << static_cast<char>(num) << "\n";
		else if (num >= 0 && num < 32)
			std::cout << "char: Non displayable"<< "\n";
		else
			std::cout << "char: impossible" << std::endl;
	}
}

void printImps(void){
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit(1);
}
void ScalarConverter::convert(const char* arg){
	std::string argStr = arg;
	if (!isValidInt(arg)){
		printImps()
	}
	isChar(arg);
	char **fuck = new char *;
	double doubl = std::strtod(arg,fuck);//static_cast<float>(atof(arg));
	float ff = static_cast<float>(doubl);
	size_t dot = countDecimals(arg);
	if (!scientificNotation(arg)){
		if ((doubl > std::numeric_limits<float>::max() || doubl < std::numeric_limits<float>::min()) && doubl > 16777215 && doubl < -16777216)
			std::cout << "float: impossible" << std::endl;
		
		std::cout << "float: " << std::fixed << std::setprecision(dot) << ff << ((dot == 0) ? ".0f" : "f") << "\n";
		std::cout << "double: " << std::fixed <<std::setprecision(dot)<< doubl << ((dot == 0) ? ".0" : "") << std::endl;
	}
}

