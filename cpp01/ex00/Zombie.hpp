/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:29:54 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/03 10:01:56 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>


class Zombie{
	private:
		std::string _name;
	public:
	Zombie(std::string);
	~Zombie();
	void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif