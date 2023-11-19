/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:00:45 by skunert           #+#    #+#             */
/*   Updated: 2023/11/16 11:34:00 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap DT1("Simon");

	DT1.whoAmI();
	DT1.FragTrap::attack("his evaluator");
	DT1.attack("his evaluator");
	DT1.guardGate();
	DT1.beRepaired(1);
	for (int i = 0; i < 47; i++)
		DT1.attack("NOBODY");
	DT1.beRepaired(50);
}