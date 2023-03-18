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

bool isValidInt(const char *arg){
	std::string str(arg);
	bool dot = false;
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && arg[i] != '\0' && i == 0)//might be a problem here
			i++;
		if (arg[i] == '.' && !dot){
			dot = true;
			i++;
		}
		if (isdigit(arg[i]) == 0)
		{
			if (arg[i] == 'f' && arg[i + 1] == '\0' && i != 0)
				continue ;
			return false;
		}
	}
	return true;
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

void printMsg(void){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
	exit(1);
}

long ft_atol(const char *arg){
	long result = 0;
	bool negative = false;

	if (*arg == '-'){
		negative = true;
		arg++;
	}
	while (*arg && *arg >= '0' && *arg <= '9'){
		result = result * 10 - (*arg - '0');
		arg++;
	}
	if (negative)
		result = -result;
	if (result > std::numeric_limits<long>::max())
		return std::numeric_limits<long>::max();
	else if (result < std::numeric_limits<long>::min())
		return std::numeric_limits<long>::min();
	return result;
}

bool isInt(const char *arg){
	long num = ft_atol(arg);
	if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
		return true;
	return false;
}

bool isFloat(const char *arg){
	long num = ft_atol(arg);
	if (num >= -16777216 && num <= 16777215)
		return true;
	return false;
}

bool isDouble(const char *arg){//this was made for long long but it's not allowed in cpp98
	long num = ft_atol(arg);
	if (num >= -9007199254740991 && num <= 9007199254740991)
		return true;
	return false;
}

void isChar(const char* arg){
	bool hasDot = false;
	for (int i = 0; arg[i]; i++){
		if (arg[i] == '.')
			hasDot = true;
	}

	int num = atoi(arg);
	if (num >= 32 && num < 127 && !hasDot)
		std::cout << "char: " << static_cast<char>(num) << "\n";
	else if (num >= 0 && num < 32 && !hasDot)
		std::cout << "char: Non displayable"<< "\n";
	else
		std::cout << "char: impossible" << std::endl;
}

bool ft_isAscii(const char* arg){
	if (static_cast<int>(arg[0]) > 31 && static_cast<int>(arg[0]) < 127 && arg[1] == '\0'){
		std::cout << "char: " << arg[0] << "\n";
		int num = static_cast<int>(arg[0]);
		std::cout << "int: " << num << "\n";
		std::cout << "float: " << static_cast<float>(num) << ".0f" << "\n";
		std::cout << "int: " <<  static_cast<double>(num) << ".0" << std::endl;
		return true;
	}
	return false;
}

void ScalarConverter::convert(const char* arg){
	if (ft_isAscii(arg))
		return ;
	if (!isValidInt(arg))
		printMsg();
	isChar(arg);
	if (isInt(arg)){
		int num_int = atoi(arg);
		std::cout << "int: " << num_int << std::endl;
	}
	else{
		std::cout << "int: Non displayable" << std::endl;
	}
	if (!scientificNotation(arg)){
		size_t dot = countDecimals(arg);
		if (isFloat(arg)){
			float num_float = static_cast<float>(atof(arg));
			if (num_float >= std::numeric_limits<float>::min() && num_float <= std::numeric_limits<float>::max())
				std::cout << "float: " << std::fixed << std::setprecision(dot) << num_float << ((dot == 0) ? ".0f" : "f") << "\n";
			else
				std::cout << "float: Non Displayable" << std::endl;
		}
		else
			std::cout << "float: Non Displayable" << std::endl;
		if (isDouble(arg)){
			double num_doubl = atof(arg);
			if (num_doubl >= std::numeric_limits<double>::min() && num_doubl <= std::numeric_limits<double>::max())
				std::cout << "double: " << std::fixed <<std::setprecision(dot)<< num_doubl << ((dot == 0) ? ".0" : "") << std::endl;
			else
				std::cout << "float: Non Displayable" << std::endl;
		}
		else
			std::cout << "double: Non displayable" << std::endl;
	}
}

