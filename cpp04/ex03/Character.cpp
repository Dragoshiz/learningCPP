#include "Character.hpp"

Character::Character(): _name("DefaultName"){
	std::cout << "\x1b[32mCharacter default constructor called\033[0m" << std::endl;
	for (int j=0; j < 4; j++)
		_inventory[j] = NULL;
}

Character::Character(std::string name):_name(name){
	std::cout << "\x1b[32mCharacter name constructor called\033[0m" << std::endl;
	for (int j=0; j < 4; j++)
		_inventory[j] = NULL;
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
	for (int j=0; j < 4; j++)
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
	int i = 0;
	while(_inventory[i++])
	if (i > 3)
		return;
	_inventory[i] = m;
}

void Character::unequip(int idx){
	if (_inventory[idx])
	{
		for (int i = idx; _inventory[i]; i++)
			_inventory[i] = _inventory[i + 1];
		_inventory[3] = NULL;
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
	for(int i=0; _inventory[i]; i++){
		std::cout << _inventory[i]->getType() << "\n";
	}
}