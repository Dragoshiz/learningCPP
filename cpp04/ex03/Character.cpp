#include "Character.hpp"

Character::Character(): _equipCount(0){
	std::cout << "\x1b[32mCharacter default constructor called\033[0m" << std::endl;
}

Character::Character(std::string name):_name(name), _equipCount(0){}

Character::Character(Character const &obj): ICharacter(obj){
	std::cout << "\x1b[33mCharacter copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Character::~Character(){
	std::cout << "\x1b[31mCharacter destructor called\033[0m" << std::endl;
}

Character& Character::operator=(Character const &obj){
	std::cout << "\x1b[33mCharacter copy assignment operator called\033[0m" << std::endl;
	this->_equipCount = obj._equipCount;
	for (int i=0; i <4; i++)
		this->_inventory[i] = obj._inventory[i];
	return *this;
}

std::string const & Character::getName(void)const{
	return this->_name;
}

void Character::equip(AMateria* m){
	if (this->_equipCount >= 4)
		return;
	this->_inventory[this->_equipCount++] = m;
}

void Character::unequip(int idx){
	if (this->_inventory[idx])
	{
		for(int i = idx; this->_inventory[i]; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[3] = NULL; 
	}
	else
		std::cout << "No item found at index: " << idx << std::endl;
}
void Character::use(int idx, ICharacter& target){
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Item not found at inxed: " << idx << std::endl;
}
