/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:39:43 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/30 14:37:26 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	int i, j;

	i = 1;
	if (argc >= 2)
	{
		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			if (argv[i + 1])
				std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}	