/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:52:42 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/02 10:41:48 by ubuntu           ###   ########.fr       */
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
	if (_num_contacts < 8)
	{
		Contact newContact;
		newContact.AddContact();
		_contacts[index] = newContact;
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
};


void PhoneBook::showContacts(int num_contacts){

	for(int i=0; i < num_contacts; i++)
	{
		std::cout << "|";
		for (int i = 0; i < 10; i++)
		{
			std::cout << " ";
		}
		std::cout << i << "|";
		printContacts(_contacts[i].getFirstname());
		printContacts(_contacts[i].getLastname());
		printContacts(_contacts[i].getNickname());
		std::cout << std::endl;
	}
};

int PhoneBook::searchContact(int num_contacts)
{
	std::cout << "Input contact index for details: ";
	int index;
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "Not a number " << std::endl;
		return 1;
	}
	if (index < 0 || index >= num_contacts)
	{
		std::cout << "Index must be in the range 0 - "<< num_contacts - 1 << std::endl;
		return 1;
	}
	std::cout << index;
	printContacts(_contacts[index].getFirstname());
	printContacts(_contacts[index].getLastname());
	printContacts(_contacts[index].getNickname());
	printContacts(_contacts[index].getDarkestSecret());
	printContacts(_contacts[index].getPhoneNumber());
	std::cout << std::endl;
	return 0;
};