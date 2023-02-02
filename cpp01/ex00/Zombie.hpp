/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:29:54 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/02 14:09:12 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie{
	private:
		std::string _name;
	public:
	void announce(void);
	Zombie* newZombie( std::string name );
	void randomChump( std::string name );
	void set_name(std::string name) {this->_name = name;}
	std::string get_name(void){return this->_name;}
	~Zombie();
};