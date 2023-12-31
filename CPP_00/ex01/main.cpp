/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:51:43 by skunert           #+#    #+#             */
/*   Updated: 2023/09/05 16:53:52 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	switch_to_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
		i++;
	}
}

int	main(void)
{
	std::string	prompt;
	PhoneBook TeleRom;

	TeleRom.set_default();
	std::cout << "Welcome to " << MAGENTA << "TeleRom " << RESET << "your trustworthy PhoneBook!" << std::endl;
	std::cout << "Valid commands are: " << "ADD " << "SEARCH " << "or EXIT\n\n";
	while (1)
	{
		std::cout << "Please enter a command: ";
		std::getline(std::cin, prompt);
		switch_to_uppercase((char *)prompt.c_str());
		if (std::cin.eof())
			break ;
		else if (prompt.empty())
		{
			std::cout << RED << "-------------------------------------------------------------\n";
			std::cout << "Your input is empty!" << std::endl;
			std::cout << RED << "-------------------------------------------------------------\n" << RESET;
			continue ;
		}
		else if (!(prompt.compare("EXIT")) && prompt.size() == 4)
			break ;
		else if (!(prompt.compare("ADD")) && prompt.size() == 3)
			TeleRom.add_new_contact();
		else if (!(prompt.compare("SEARCH")) && prompt.size() == 6)
			TeleRom.display_contacts();
		else
		{
			std::cout << RED << "-------------------------------------------------------------";
			std::cout << "\nPlease enter a valid command!" << std::endl;
			std::cout << "Valid commands are: " << "ADD " << "SEARCH " << "or EXIT\n";
			if (prompt[prompt.size() - 1] == ' ')
				std::cout << "Be careful about backspaces!!!" << std::endl;
			std::cout << "-------------------------------------------------------------" << RESET << std::endl;
		}
	}
}
