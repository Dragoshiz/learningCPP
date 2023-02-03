/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:31:17 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/02 16:03:09 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " got constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " was destroied" << std::endl;
}

void Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
