/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:42:23 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/01 19:17:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){
	// std::cout << "Contact constructor called" << std::endl;
};

Contact::~Contact()
{
	// std::cout << "Contact Destructor called" << std::endl;
};

//returns useless as cin does not take bare enter
int Contact::AddContact(){
	std::cout << "First name: ";
	std::cin >> this->_first_name;
	setFirstname(this->_first_name);
	if (this->_first_name.empty())
		return 1;
	
	std::cout << "Last name: ";
	std::cin >> this->_last_name;
	setLastname(this->_last_name);
	if (this->_last_name.empty())
		return 1;
	
	std::cout << "Nickname: ";
	std::cin >> this->_nickname;
	setNickname(this->_nickname);
	if (this->_nickname.empty())
		return 1;
	
	std::cout << "Darkest secret: ";
	std::cin >> this->_darkest_secret;
	setDarkestSecret(this->_darkest_secret);
	if (this->_darkest_secret.empty())
		return 1;

	std::cout << "Phone number: ";
	std::cin >> this->_phone_number;
	setPhoneNumber(this->_phone_number);
	if (this->_phone_number.empty())
		return 1;
	return 0;
};

std::string Contact::getFirstname(){
	return this->_first_name;
};

void Contact::setFirstname(std::string new_first_name){
	this->_first_name = new_first_name;
};

std::string Contact::getLastname(){
	return this->_last_name;
};

void Contact::setLastname(std::string new_last_name){
	this->_last_name = new_last_name;
};

std::string Contact::getNickname(){
	return this->_nickname;
};

void Contact::setNickname(std::string new_nickname){
	this->_nickname = new_nickname;
};
std::string Contact::getDarkestSecret(){
	return this->_darkest_secret;
};

void Contact::setDarkestSecret(std::string new_secret){
	this->_darkest_secret = new_secret;
};

std::string Contact::getPhoneNumber(){
	return this->_phone_number;
};

void Contact::setPhoneNumber(std::string new_phone_nb){
	this->_phone_number = new_phone_nb;
};
