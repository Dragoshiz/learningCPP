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
	return (str.size() - decimPos - ((str.find('f') == std::string::npos)? 1 : 2));
}

bool	isScientific(const char* arg){
	std::string args = arg;
	std::string arr[8] = {"inf","inff","nan","nanf","-inf","-inff", "+inf", "+inff"};
	int i = 0;
	while (i < 8 && args.compare(arr[i]) != 0)
		i++;
	return (i < 8);
}

bool	scientificNotation(const char* arg){
	std::string args = arg;
	std::string arr[8] = {"inf","inff","nan","nanf","-inf","-inff", "+inf", "+inff"};
	int i = 0;
	while (i < 8 && args.compare(arr[i]) != 0)
		i++;
	if (i < 8)
	{
		std::cout << "char: impossible" << "\n";
		std::cout << "int: impossible" << "\n";
		std::cout << "float: " << ((i % 2 ==0)? arr[i + 1] : arr[i]) << "\n";
		std::cout << "double: " << ((i % 2 ==0)? arr[i] : arr[i - 1]) << std::endl;
		return true;
	}
	return false;
}

void printMsg(const char* arg){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (!scientificNotation(arg)){
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
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

bool checkDecimalPoint(const char* arg, size_t pos){
	pos++;
	while(arg[pos]){
		if (arg[pos] != '0')
			return false;
		pos++;
	}
	return true;
}

void printChar(double num){
	if (num >= 0 && num < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (num >= 32 && num < 127)
		std::cout << "char: " <<  static_cast<char>(num) << "\n";
	else
		std::cout << "char: impossible" << "\n";
}

void convertChar(const char* arg){
	int num = static_cast<int>(arg[0]);
	std::cout << "char: " << arg[0] << "\n";
	std::cout << "int: " << num << "\n";
	std::cout << "float: " << static_cast<float>(num) << ".0f" << "\n";
	std::cout << "double: " << static_cast<double>(num) << ".0" << std::endl;
}

void convertInt(const char* arg){
	long num = atol(arg);
	double doubl_num = atof(arg);
	size_t dot = countDecimals(arg);
	printChar(num);
	if (num > -2147483648 && num < 2147483647)
		std::cout << "int: " << static_cast<int>(num) << "\n";
	else
		std::cout << "int: impossible" << "\n";
	if ((static_cast<float>(doubl_num) >= -std::numeric_limits<float>::max() && static_cast<float>(doubl_num) <= std::numeric_limits<float>::max()))
			std::cout << "float: " << std::fixed << std::setprecision(dot) << static_cast<float>(doubl_num) << ((dot == 0) ? ".0f" : "f") << "\n";
	else
		std::cout << "float: impossible" << "\n";
	if ((num >= -std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::max()))
		std::cout << "double: " << std::fixed <<std::setprecision(dot)<< num << ((dot == 0) ? ".0" : "") << std::endl;
	else
		std::cout << "double: Non Displayable" << std::endl;
}

void convertFloat(const char* arg){
	std::string argmnt = arg;
	double num = atof(arg);
	size_t dot = countDecimals(arg);
	size_t pos = argmnt.find('.');
	if (arg[pos + 1] == '0' && checkDecimalPoint(arg, pos))
		printChar(num);
	else
		std::cout << "char: impossible" << "\n";
	if (num > -2147483648 && num < 2147483647)
		std::cout << "int: " << static_cast<int>(num) << "\n";
	else
		std::cout << "int: impossible" << "\n";
	if ((static_cast<float>(num) >= -std::numeric_limits<float>::max() && static_cast<float>(num) <= std::numeric_limits<float>::max()))
		std::cout << "float: " << std::fixed << std::setprecision(dot) << static_cast<float>(num) << ((dot == 0) ? ".0f" : "f") << "\n";
	else
		std::cout << "float: impossible" << "\n";
	if ((num >= -std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::max()))
		std::cout << "double: " << std::fixed <<std::setprecision(dot)<< num << ((dot == 0) ? ".0" : "") << std::endl;
	else
		std::cout << "double: Non Displayable" << std::endl;

}

void convertDouble(const char* arg){
	std::string argmnt = arg;
	double num = atof(arg);
	size_t dot = countDecimals(arg);
	size_t pos = argmnt.find('.');
	if (arg[pos + 1] == '0' && checkDecimalPoint(arg, pos))
		printChar(num);
	else
		std::cout << "char: impossible" << "\n";
	if (num > -2147483648 && num < 2147483647)
		std::cout << "int: " << static_cast<int>(num) << "\n";
	else
		std::cout << "int: impossible" << "\n";
	if ((static_cast<float>(num) >= -std::numeric_limits<float>::max() && static_cast<float>(num) <= std::numeric_limits<float>::max()))
			std::cout << "float: " << std::fixed << std::setprecision(dot) << static_cast<float>(num) << ((dot == 0) ? ".0f" : "f") << "\n";
	else
		std::cout << "float: impossible" << "\n";
	if ((num >= -std::numeric_limits<double>::max() && num <= std::numeric_limits<double>::max()))
		std::cout << "double: " << std::fixed <<std::setprecision(dot)<< num << ((dot == 0) ? ".0" : "") << std::endl;
	else
		std::cout << "double: Non Displayable" << std::endl;
}

bool isChar(const char *arg){
	int decimal = static_cast<int>(arg[0]);
	return (arg[1] == '\0' && decimal > 31 && decimal < 127 && !isdigit(arg[0]));
}

bool isInt(const char *arg){
	bool negative = false;
	for (int i = 0; arg[i]; i++){
		if (arg[i] == '-' && !negative){
			negative = true;
			i++;
		}
		if (!isdigit(arg[i]))
			return false;
	}
	return true;
}

bool isFloat(const char* arg){
	bool dot = false;
	int i = 0;
	if (arg[0] == '-')
		i++;
	while(arg[i]){
		if (!isdigit(arg[i])){
			if (arg[i] == '.' && !dot)
			{
				dot = true;
				i++;
				continue;
			}
			if (arg[i] == 'f' && arg[i - 1] != '.' && arg[i + 1] == '\0' && i > 0 && dot)
			{
				return true;
			}
			return false;
		}
		i++;
	}
	return false;
}

bool isDouble(const char* arg){
	bool dot = false;
	int i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i]){
		if (!isdigit(arg[i])){
			if (arg[i] == '.' && !dot && arg[i + 1] != '\0')
			{
				dot = true;
				i++;
				continue;
			}
			return false;
		}
		i++;
	}
	return dot;
}

bool (*validator[])(const char *) = {isChar, isInt, isFloat, isDouble, isScientific};

void ScalarConverter::convert(const char* arg){
	for (int i = 0; i < 5; i++){
		if(validator[i](arg)){
			switch (i)
			{
			case 0:
				convertChar(arg);
				return;
			case 1:
				convertInt(arg);
				return;
			case 2:
				convertFloat(arg);
				return;
			case 3:
				convertDouble(arg);
				return;
			case 4:
				scientificNotation(arg);
				return;
			default:
				std::cout << "Invalid argument" << std::endl;
				return;
			}
		}
	}
	std::cout << "Invalid argument" << std::endl;
}
