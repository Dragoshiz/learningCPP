#include "Brain.hpp"

Brain::Brain(){
	std::cout << "\x1b[32mBrain default constructor called\033[0m" << std::endl;
}

Brain::Brain(Brain const &obj){
	std::cout << "\x1b[33mBrain copy constructor called\033[0m" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
}

Brain::~Brain(){
	std::cout << "\x1b[31mBrain destructor called\033[0m" << std::endl;
}

Brain& Brain::operator=(Brain const &obj){
	std::cout << "\x1b[33mBrain copy assignment operator called\033[0m" << std::endl;
	for(int i = 0; i < 100; i++)
		_ideas[i] = obj._ideas[i];
	return *this;
}

void Brain::setIdeas(std::string idea){
	int i = 0;
	while(!_ideas[i].empty())
		i++;
	_ideas[i] = idea;
}

void Brain::getIdeas(void){
	int i = 0;
	while(!_ideas[i].empty())
		std::cout << _ideas[i++] << "\n";
}