/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:02:53 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/31 11:33:59 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(int argc, char *argv[])
{
	PhoneBook pBook;
	int	contact_numb = 0;
	if (strcmp(argv[1], "ADD") == 0 && contact_numb < 8)
	{
		pBook::conta
		contact_numb ++;
	}
	else if (strcmp(argv[1], "SEARCH") == 0)
		std::cout << "search" << std::endl;
	else if (strcmp(argv[1], "EXIT") == 0)
		std::cout << "exit" << std::endl;
	return (0);
}