/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:52:42 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/01 16:29:37 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(){
	// std::cout << "Phonebook constructor called" << std::endl;
};

PhoneBook::~PhoneBook(){
	// std::cout << "Phonebook destructor called" << std::endl;
};

void PhoneBook::addContact2arr(int index){
	if (num_contacts < 8)
	{
		Contact newContact;
		newContact.AddContact();
		contacts[index] = newContact;
	}
};

void	PhoneBook::printContacts(std::string str)
{
	std::string tmp;
	tmp = str;
	for (int i = str.length(); i < 10; i++)
	{
		std::cout << " ";
	}
	if (str.length() > 10)
	{
		unsigned size;
		tmp.resize(10);
		tmp[9] = '.';

	}
	std::cout << tmp << "|";
}


void PhoneBook::showContacts(int num_contacts){

	for(int i=0; i < num_contacts; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << " ";
		}
		std::cout << i << "|";
		printContacts(contacts[i].getFirstname());
		printContacts(contacts[i].getLastname());
		printContacts(contacts[i].getNickname());
		std::cout << std::endl;
	}
	std::cout << "Contact index for details: ";
	int index;
	std::cin >> index;
	
};