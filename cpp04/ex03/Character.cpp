#include "Character.hpp"

Character::Character(): _name("DefaultName"), _equipCount(0){
	for (int j=0; j < 4; j++)
		_inventory[j] = NULL;
	std::cout << "\x1b[32mCharacter default constructor called\033[0m" << std::endl;
}

Character::Character(std::string name):_name(name), _equipCount(0){
	for (int j=0; j < 4; j++)
		_inventory[j] = NULL;
	std::cout << "\x1b[32mCharacter name constructor called\033[0m" << std::endl;
}

Character::Character(Character const &obj): ICharacter(obj){
	std::cout << "\x1b[33mCharacter copy constructor called\033[0m" << std::endl;
	*this = obj;
}

Character::~Character(){
	std::cout << "\x1b[31mCharacter destructor called\033[0m" << std::endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Character& Character::operator=(Character const &obj){
	std::cout << "\x1b[33mCharacter copy assignment operator called\033[0m" << std::endl;
	for (int j=0; j < _equipCount; j++)
	{
		delete _inventory[j];
		_inventory[j] = NULL;
		if(obj._inventory[j])
			_inventory[j] = obj._inventory[j]->clone();
	}
	return *this;
}

std::string const & Character::getName(void)const{
	return _name;
}

void Character::equip(AMateria* m){
	if (_equipCount >= 4)
		return;
	_inventory[_equipCount++] = m;
}

void Character::unequip(int idx){
	if (_inventory[idx])
	{
		for (int i = idx; _inventory[i]; i++)
			_inventory[i] = _inventory[i + 1];
		_inventory[3] = NULL;
		_equipCount--;
	}
	else
		std::cout << "No item to unequip found at index: " << idx << std::endl;
}
void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index for inventory!" << std::endl;
		return;
	}
	else if (_inventory[idx])
		_inventory[idx]->use(target);
	else
	{
		std::cout << "Item not found at index: " << idx << std::endl;
	}
}

void Character::getMaterias(void){
	for(int i=0; i < _equipCount; i++){
		std::cout << _inventory[i]->getType() << "\n";
	}
}