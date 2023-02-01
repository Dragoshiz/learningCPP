/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:02:53 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/31 13:27:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	PhoneBook pBook;
	if (strcmp(argv[1], "ADD") == 0)
	{
		pBook.addContact();

		std::cout<< pBook.contacts[0].first_name << std::endl;
	}
	else if (strcmp(argv[1], "SEARCH") == 0)
		std::cout << "search" << std::endl;
	else if (strcmp(argv[1], "EXIT") == 0)
		std::cout << "exit" << std::endl;
	return (0);
}