#!/bin/bash

read -p "Enter file/class name: " filename

read -p "Do you need a main/makefile? (type y or n) " yn

touch "${filename}.hpp"
touch "${filename}.cpp"

if [ "$yn" == "y" ]
then
	touch "main.cpp"
	touch "Makefile"
fi

nano ${filename}.hpp
filename_upper=$(echo "${filename}" | tr '[:lower:]' '[:upper:]')

cat << EOF > "${filename}.hpp"
#ifndef ${filename_upper}_HPP
#define ${filename_upper}_HPP
#include <iostream>

class ${filename}{
	public:
		${filename}();
		${filename}(${filename} const &);
		~${filename}();
		${filename}& operator=(${filename} const &);
	private:
};
#endif

EOF

cat << EOF > "${filename}.cpp"
#include "${filename}.hpp"

${filename}::${filename}(){
	std::cout << "\x1b[32m${filename} default constructor called\033[0m" << std::endl;
}

${filename}::${filename}(${filename} const &obj){
	std::cout << "\x1b[33m${filename} copy constructor called\033[0m" << std::endl;
	*this = obj;
}

${filename}::~${filename}(){
	std::cout << "\x1b[31m${filename} destructor called\033[0m" << std::endl;
}

${filename}& ${filename}::operator=(${filename} const &obj){
	//assign obj to this variables!
	std::cout << "\x1b[33m${filename} copy assignment operator called\033[0m" << std::endl;
}

EOF

if [ "$yn" == "y" ]
then
cat << EOF > "main.cpp"
#include "${filename}.hpp"

int main(){
	//write your program.. special thanks to dimbrea
	return 0;
}

EOF

fi
echo "Files : ${filename}.hpp and ${filename}.cpp created and populated successfuly."