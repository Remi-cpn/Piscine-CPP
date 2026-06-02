/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:17:44 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:39:41 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

#define DIM		"\033[2m"
#define RESET   "\033[0m"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
MateriaSource::MateriaSource(void)
{
	std::cout << DIM << "MateriaSource default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
    _spells[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource& srcMateriaSource)
{
	std::cout << DIM << "MateriaSource copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
    _spells[i] = NULL;
	*this = srcMateriaSource;
}
MateriaSource::~MateriaSource(void)
{
	std::cout << DIM << "MateriaSource destructor called" << RESET << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (_spells[i] != NULL)
		{
			delete _spells[i];
			_spells[i] = NULL;
		}
	}
}



/* ——— Methodes ————————————————————————————————————————————————————————————— */
void MateriaSource::learnMateria(AMateria* newMateria)
{
	for (int i = 0; i < 4; i++)
	{
		if (_spells[i] == NULL)
		{
			_spells[i] = newMateria;
			return;
		}
	}
	std::cout << "SpellBook is full." << std::endl;
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_spells[i] != NULL && _spells[i]->getType() == type)
			return _spells[i]->clone();
	}
	std::cout << "Don't know this spell." << std::endl;
	return 0;
}


/* ——— Operator overload ———————————————————————————————————————————————————— */
MateriaSource& MateriaSource::operator=(const MateriaSource& srcMateriaSource)
{
	for (int i = 0; i < 4; i++)
	{
		if (_spells[i] != NULL)
		{
			delete _spells[i];
			_spells[i] = NULL;
		}
		if (srcMateriaSource._spells[i] != NULL)
			_spells[i] = srcMateriaSource._spells[i]->clone();
	}
	return *this;
}