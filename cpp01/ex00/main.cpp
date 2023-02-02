/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:29:41 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/02 14:52:10 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie stackZmbie;
	Zombie *heapZmbie;
	stackZmbie.randomChump("Roger");
	heapZmbie->newZombie("Edward");
	std::cout << heapZmbie->get_name() << "heap created zombie" << std::endl;
	delete heapZmbie;
	return 0;
}