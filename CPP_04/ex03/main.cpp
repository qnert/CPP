/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:40:11 by skunert           #+#    #+#             */
/*   Updated: 2023/11/23 19:56:39 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

void	test_from_subject(void)
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
}

void	test_with_unequip(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria*		trash[4];
	int				i = 0;
	std::cout << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	trash[i++] = tmp;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	trash[i++] = tmp;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	for (int x = 0; x < i; x++)
		delete trash[x];
}

int main()
{
// 	test_from_subject();

	test_with_unequip();
	// system("leaks pets");
	return 0;
}
