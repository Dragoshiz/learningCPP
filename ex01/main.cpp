/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:02:53 by dimbrea           #+#    #+#             */
/*   Updated: 2023/02/01 19:01:43 by ubuntu           ###   ########.fr       */
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
				if (num_contacts < 8)
					phonebook.addContact2arr(num_contacts++);
				else
					phonebook.addContact2arr(7);
			}
			else if (input.compare("SEARCH") == 0)
			{
				phonebook.showContacts(num_contacts);
			}
			else if (input.compare("EXIT") == 0)
				break ;
			if (std::cin.eof())
				break ;
		}
	}
	else
		std::cout << "No arguments needed" << std::endl;
	return (0);
}