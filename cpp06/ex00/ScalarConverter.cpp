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

bool isValidNum(const char *arg){
	std::string str(arg);
	bool dot = false;
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && arg[i + 1] != '\0' && i == 0)//might be a problem here
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

// bool isInt(const char *arg){
// 	long num = ft_atol(arg);
// 	if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
// 		return true;
// 	return false;
// }

// bool isFloat(const char *arg){
// 	long num = ft_atol(arg);
// 	if (num >= -16777216 && num <= 16777215)
// 		return true;
// 	return false;
// }

// bool isDouble(const char *arg){//this was made for long long but it's not allowed in cpp98
// 	long num = ft_atol(arg);
// 	if (num >= -9007199254740991 && num <= 9007199254740991)
// 		return true;
// 	return false;
// }

// void isChar(const char* arg){
// 	bool hasDot = false;
// 	for (int i = 0; arg[i]; i++){
// 		if (arg[i] == '.' && arg[i + 1] != '0')
// 			hasDot = true;
// 	}

// 	int num = atoi(arg);
// 	if (num >= 32 && num < 127 && !hasDot)
// 		std::cout << "char: " << static_cast<char>(num) << "\n";
// 	else if (num >= 0 && num < 32 && !hasDot)
// 		std::cout << "char: Non displayable"<< "\n";
// 	else
// 		std::cout << "char: impossible" << std::endl;
// }

void convertChar(const char* arg){
	int num = static_cast<int>(arg[0]);
	std::cout << "char: " << arg[0] << "\n";
	std::cout << "int: " << num << "\n";
	std::cout << "float: " << num << ".0f" << "\n";
	std::cout << "double: " << num << ".0" << std::endl;
}

void convertInt(const char* arg){
	int num = atoi(arg);
	double doubl_num = atof(arg);
	if (num >= 0 && num < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (num >= 32 && num < 127)
		std::cout << "char: " <<  static_cast<char>(num) << "\n";
	else
		std::cout << "char: impossible" << "\n";
	std::cout << "int: " << num << "\n";
	if (doubl_num > -std::numeric_limits<float>::max() && doubl_num < std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(num) << ".0f" << "\n";
	else
		std::cout << "float: impossible" << "\n";
	std::cout << "int: " << static_cast<int>(num) << ".0" << std::endl;
}

bool ft_isAscii(const char* arg){
	if (static_cast<int>(arg[0]) > 31 && static_cast<int>(arg[0]) < 127 && arg[1] == '\0' && !isdigit(arg[0])){
		std::cout << "char: " << arg[0] << "\n";
		int num = static_cast<int>(arg[0]);
		std::cout << "int: " << num << "\n";
		std::cout << "float: " << static_cast<float>(num) << ".0f" << "\n";
		std::cout << "int: " <<  static_cast<double>(num) << ".0" << std::endl;
		return true;
	}
	return false;
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
	long num = ft_atol(arg);
	if (num > -2147483648 && num < 2147483647)
		return true;
	return false;
}

bool isFloat(const char* arg){ //to be checked if it's the last one
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

bool isDouble(const char* arg){ //to be checked
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

bool (*validator[])(const char *) = {isChar, isInt, isFloat, isDouble};

void ScalarConverter::convert(const char* arg){
	for (int i = 0; i < 5; i++){
		if(validator[i](arg)){
			switch (i)
			{
			case 0:
				convertChar(arg);
				break;
			case 1:
				convertInt(arg);
				break;
			case 2:
				std::cout << "float.\n";
				break;
			case 3:
				std::cout << "double.\n";
				break;
			case 4:
				scientificNotation(arg);
				break;
			default:
				break;
			}
		}
	}
}

// void ScalarConverter::convert(const char* arg){
// 	std::string d = arg;
// 	if (ft_isAscii(arg))
// 		return ;
// 	if (!isValidInt(arg))
// 		printMsg(arg);
// 	isChar(arg);
// 	if (isInt(arg)){
// 		int num_int = atoi(arg);
// 		std::cout << "int: " << num_int << std::endl;
// 	}
// 	else{
// 		std::cout << "int: Non displayable" << std::endl;
// 	}
// 	size_t dot = countDecimals(arg);
// 		//problems always
// 		double num_doubl = atof(arg);
// 		if ((static_cast<float>(num_doubl) >= FLT_MIN && static_cast<float>(num_doubl) <= FLT_MAX)) //|| std::abs(num_float) < 0.0001)
// 			std::cout << "float: " << std::fixed << std::setprecision(dot) << static_cast<float>(num_doubl) << ((dot == 0) ? ".0f" : "f") << "\n";
// 		else
// 			std::cout << "float: Non Displayable" << std::endl;
		
// 		if ((num_doubl >= std::numeric_limits<double>::min() && num_doubl <= std::numeric_limits<double>::max()))
// 			std::cout << "double: " << std::fixed <<std::setprecision(dot)<< num_doubl << ((dot == 0) ? ".0" : "") << std::endl;
// 		else
// 			std::cout << "double: Non Displayable" << std::endl;
// }