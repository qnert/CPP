/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:36:05 by skunert           #+#    #+#             */
/*   Updated: 2023/09/07 16:22:02 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string	switch_to_uppercase(std::string str)
{
	unsigned long	i;

	i = 0;
	while (i < str.size())
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int	i;
	std::string tmp;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[++i] != NULL)
		{
			tmp = switch_to_uppercase(argv[i]);
			std::cout << tmp;
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
