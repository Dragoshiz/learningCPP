/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:02:53 by dimbrea           #+#    #+#             */
/*   Updated: 2023/02/01 11:33:46 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Welcome to the 80s PhoneBook!"<< std::endl;
		Contact		new_contact;
		PhoneBook	phonebook;
		std::string	input;
		int num_contacts = 0;
		while(1)
		{
			std::cout << "You can use the keyword ADD, SEARCH, EXIT"<< std::endl;
			std::cin >> input;
			if (input.compare("ADD") == 0)
			{
				if (new_contact.AddContact() == 1)
					std::cout << "Field left empty!" << std::endl;
					
				
			}
			else if (input.compare("SEARCH") == 0)
				std::cout << "search" << std::endl;
			else if (input.compare("EXIT") == 0)
				std::cout << "exit" << std::endl;
		}
	}
	std::cout << "No arguments needed" << std::endl;
	return (0);
}