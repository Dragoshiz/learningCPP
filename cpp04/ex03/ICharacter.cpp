#include "ICharacter.hpp"

ICharacter::ICharacter(){
	std::cout << "\x1b[32mICharacter default constructor called\033[0m" << std::endl;
}

ICharacter::ICharacter(ICharacter const &obj){
	std::cout << "\x1b[33mICharacter copy constructor called\033[0m" << std::endl;
	*this = obj;
}

ICharacter::~ICharacter(){
	std::cout << "\x1b[31mICharacter destructor called\033[0m" << std::endl;
	// delete[] this->_inventory;
}

ICharacter& ICharacter::operator=(ICharacter const &obj){
	std::cout << "\x1b[33mICharacter copy assignment operator called\033[0m" << std::endl;
	(void)obj;
	return *this;
}

// std::string const & ICharacter::getName(void)const{
// 	return this->_name;
// }

// void ICharacter::equip(AMateria* m){
// 	if (this->_equipCount >= 4)
// 		return;
// 	this->_inventory[this->_equipCount++] = m;
// }

// void ICharacter::unequip(int idx){
// 	if (this->_inventory[idx])
// 	{
// 		for(int i = idx; this->_inventory[i]; i++)
// 			this->_inventory[i] = this->_inventory[i + 1];
// 		this->_inventory[3] = nullptr; // it should be NULL but lets see if c98 flag works
// 	}
// 	else
// 		std::cout << "No item found at index: " + idx << std::endl;
// }
// void ICharacter::use(int idx, ICharacter& target){
// 	if (this->_inventory[idx])
// 		this->_inventory[idx]->use(target);
// 	else
// 		std::cout << "Item not found at inxed: " + idx << std::endl;
// }