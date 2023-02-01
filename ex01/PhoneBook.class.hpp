/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:04:22 by dimbrea           #+#    #+#             */
/*   Updated: 2023/02/01 16:30:19 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.class.hpp"

class PhoneBook{
	private:
		int num_contacts;
		Contact contacts[8];
	public:
		// PhoneBook():num_contacts(0){};
		PhoneBook(void);
		~PhoneBook(void);
		
		void addContact2arr(int index);
		void showContacts(int num_contacts);
		void printContacts(std::string str);
};
#endif