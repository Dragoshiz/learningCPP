#include "RPN.hpp"

void errMsgs(int msg){
	switch (msg){
		case 1:
			std::cout << "Error: 1 argument needed" << std::endl;
			break;
		case 2:
			std::cout << "Error: wrong charachter found -> ";
			break;
		case 3:
			std::cout << "Error: with the operators" << std::endl;
			break;
		case 4:
			std::cout << "Error: not a good RPN rule" << std::endl;
			break;
		case 5:
			std::cout << "Error: only a digit was given" << std::endl;
	}
}

bool check_operators(char op){
	char operators[] = {'+', '-', '*', '/'};

	for (int i=0; i < 4; i++){
		if(operators[i] == op){
			return true;
		}
	}
	return false;
}

bool check_arg(char *argv){
	size_t i = 0;
	size_t digits = 0;
	size_t oper = 0;
	while(argv[i] != '\0'){
 		if (std::isdigit(argv[i]))
			digits++;
		else if(check_operators(argv[i]))
			oper++;
		else if (argv[i] == ' '){
			i++;
			continue;
		}
		else{
			errMsgs(2);
			std::cout << argv[i] << std::endl;
			return false;
		}
		i++;
	}
	if (oper != digits - 1 || oper == 0){
		if (oper == 0)
			errMsgs(5);
		else
			errMsgs(3);
		return false;
	}
	return true;
}

double operation(double l, double r, char oper ){
	switch (oper)
	{
		case '+':
			return l + r;
		case '-':
			return l - r;
		case '*':
			return l * r;
		case '/':
			return l / r;
	}
	return 0;
}

void push_and_calc(std::stack<double>& d_stack, char *argv){
	int i = 0;
	while(argv[i]){
		if (std::isdigit(argv[i]))
			d_stack.push(argv[i] - '0');
		else if(argv[i] == ' '){
			i++;
			continue;
		}
		else if (check_operators(argv[i]) && d_stack.size() >= 2){
			double r_operand = d_stack.top();
			d_stack.pop();
			double l_operand = d_stack.top();
			d_stack.pop();
			d_stack.push(operation(l_operand, r_operand, argv[i]));
		}
		else{
			errMsgs(4);
			return;	
		}
		i++;
	}
	if (d_stack.size() != 1){
		errMsgs(4);
		return;
	}
	else
		std::cout << d_stack.top() << std::endl; 
}