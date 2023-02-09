#include <iostream>
#include <fstream>
#include <string>


std::string toReplace(std::string str, std::string s1, std::string s2)
{
	std::string replace;
	size_t pos = 0;
	while (pos < str.length())
	{
		size_t found = str.find(s1, pos);
		if (found == std::string::npos)
		{
			replace += str.substr(pos);
			break ;
		}
		replace += str.substr(pos, found - pos);
		replace += s2;
		pos = found + s1.length();
	}
	return replace;
}

int main(int argc, char *argv[])
{
	std::string line;
	std::fstream file;

	if (argc != 4)
	{
		std::cout << "3 arguments are needed" << std::endl;
		return 1;
	}
	file.open(argv[1], std::ios::in | std::ios::out);
	if (!file)
	{
		std::cout << "Problem opening the file" << std::endl;
		return 1;
	}
	std::string filename = std::string(argv[1]) + ".replace";
	std::ofstream replacedFile(filename.c_str());
	if (replacedFile.is_open())
	{
		while(std::getline(file, line))
		{
			replacedFile << toReplace(line, argv[2], argv[3]);
			if (!file.eof())
				replacedFile << std::endl;
		}
	}
	else
	{
		std::cout << "Unable to open file for writing" << std::endl;
		return 1;
	}
	replacedFile.close();
	file.close();
	return 0;
}