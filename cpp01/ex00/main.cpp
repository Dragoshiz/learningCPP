/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:29:41 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/03 10:01:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZmbie;

	randomChump("Roger");
	heapZmbie = newZombie("Eduard");
	heapZmbie->announce();
	delete heapZmbie;
	return 0;
}