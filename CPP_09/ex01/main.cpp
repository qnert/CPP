/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:59:02 by skunert           #+#    #+#             */
/*   Updated: 2023/12/11 15:28:05 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av){
	if (ac != 2)
		return (-1);
	try{
		std::cout << av[1] << std::endl;
		RPN A(av[1]);
		A.calculate_RPN();
	}
	catch (std::exception& e){
		std::cout << e.what();
		return (-1);
	}
	return (0);
}
