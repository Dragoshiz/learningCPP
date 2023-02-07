#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>

class Weapon{
	private:
		std::string type;
	public:
		Weapon(std::string type);
		~Weapon();
		void setType(std::string type){this->type = type;};
		const std::string& getType(void);
};


#endif