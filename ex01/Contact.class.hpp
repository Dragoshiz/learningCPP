/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:04:46 by dimbrea           #+#    #+#             */
/*   Updated: 2023/02/01 19:17:03 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>


class Contact{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _darkest_secret;
		std::string _phone_number;
	public:
		Contact(void);
		~Contact(void);
		int AddContact(void);
		std::string	getFirstname(void);
		void		setFirstname(std::string);
		std::string getLastname(void);
		void 		setLastname(std::string);
		std::string getNickname(void);
		void		setNickname(std::string);
		std::string getDarkestSecret(void);
		void		setDarkestSecret(std::string);
		std::string getPhoneNumber(void);
		void		setPhoneNumber(std::string);
};

#endif