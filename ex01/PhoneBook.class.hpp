/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:04:22 by dimbrea           #+#    #+#             */
/*   Updated: 2023/02/01 11:27:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "Contact.class.hpp"

class PhoneBook{
	private:
		Contact Contacts[7];
	public:
		PhoneBook(void);
		~PhoneBook(void);
};
#endif