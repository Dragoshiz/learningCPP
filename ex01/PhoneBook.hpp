/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:04:22 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/31 13:42:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "Contact.hpp"


class PhoneBook{
private:
	int numContacts = 0;
public:
	Contact contacts[8];
	char *str = new char;
	// PhoneBook() : numContacts(){};
	void addContact(){
		std::string data;
		if (numContacts < 8)
		{
			std::cout << "First name: ";
			std::cin >> str;
			contacts[numContacts++] = Contact();
		}
	}
};
#endif