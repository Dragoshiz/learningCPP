/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:42:23 by ubuntu            #+#    #+#             */
/*   Updated: 2023/02/01 13:35:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(){
	std::cout << "Contact constructor called" << std::endl;
};

Contact::~Contact()
{
	std::cout << "Contact Destructor called" << std::endl;
};

//returns useless as cin does not take bare enter
int Contact::AddContact(){
	std::cout << "First name: ";
	std::cin >> this->first_name;
	setFirstname(this->first_name);
	if (this->first_name.empty())
		return 1;
	
	std::cout << "Last name: ";
	std::cin >> this->last_name;
	setLastname(this->last_name);
	if (this->last_name.empty())
		return 1;
	
	std::cout << "Nickname: ";
	std::cin >> this->nickname;
	setNickname(this->nickname);
	if (this->nickname.empty())
		return 1;
	
	std::cout << "Darkest secret: ";
	std::cin >> this->darkest_secret;
	setDarkestSecret(this->darkest_secret);
	if (this->darkest_secret.empty())
		return 1;

	std::cout << "Phone number: ";
	std::cin >> this->phone_number;
	setPhoneNumber(this->phone_number);
	if (this->phone_number.empty())
		return 1;
	return 0;
};

std::string Contact::getFirstname(){
	return this->first_name;
};

void Contact::setFirstname(std::string new_first_name){
	this->first_name = new_first_name;
};

std::string Contact::getLastname(){
	return this->last_name;
};

void Contact::setLastname(std::string new_last_name){
	this->last_name = new_last_name;
};

std::string Contact::getNickname(){
	return this->nickname;
};

void Contact::setNickname(std::string new_nickname){
	this->nickname = new_nickname;
};
std::string Contact::getDarkestSecret(){
	return this->darkest_secret;
};

void Contact::setDarkestSecret(std::string new_secret){
	this->darkest_secret = new_secret;
};

std::string Contact::getPhoneNumber(){
	return this->phone_number;
};

void Contact::setPhoneNumber(std::string new_phone_nb){
	this->phone_number = new_phone_nb;
};
