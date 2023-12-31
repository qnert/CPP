/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunert <skunert@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:34:28 by skunert           #+#    #+#             */
/*   Updated: 2023/11/23 16:54:39 by skunert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called.\n";
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_slots[i] != NULL)
				delete this->_slots[i];
			if (other._slots[i] != NULL)
				this->_slots[i] = other._slots[i]->clone();
			else
				this->_slots[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource default destructor called.\n";
	for (int i = 0; i < 4; i++)
		delete (this->_slots[i]);
}

void		MateriaSource::learnMateria(AMateria* other)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = other;
			return ;
		}
	}
	std::cout << "This MateriaSource can't learn more materias.\n";
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] && this->_slots[i]->getType() == type)
			return (this->_slots[i]->clone());
	}
	std::cout << "The type given matches no valid materia.\n";
	return (NULL);
}
