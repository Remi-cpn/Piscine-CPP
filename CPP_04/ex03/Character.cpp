/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:10:30 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:39:51 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Character::Character(void)
{
	std::cout << DIM << "Character default constructor called" << RESET << std::endl;
	_name = "...";
	for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
    _floor[i] = NULL;
}
Character::Character(const Character& srcCharacter)
{
	std::cout << DIM << "Character copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
    _floor[i] = NULL;
	*this = srcCharacter;
}
Character::Character(std::string const & name)
{
	std::cout << DIM << "Character type constructor called" << RESET << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
    _inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
    _floor[i] = NULL;
}
Character::~Character(void)
{
	std::cout << DIM << "Character destructor called" << RESET << std::endl;
	
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (_floor[i] != NULL)
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}
}


/* ——— Getters & Setters ———————————————————————————————————————————————————— */
std::string const & Character::getName() const { return _name;}



/* ——— Methodes ————————————————————————————————————————————————————————————— */
void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full." << std::endl;
}
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;
		
	for (int i = 0; i < 100; i++)
	{
		if (_floor[i] == NULL)
		{
			_floor[i] = _inventory[idx];
			_inventory[idx] = NULL;
			return;
		}
	}
	std::cout << "Floor is full." << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || _inventory[idx] == NULL)
		return;
	
	_inventory[idx]->use(target);
}




/* ——— Operator overload ———————————————————————————————————————————————————— */
Character& Character::operator=(const Character& srcCharcater)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (srcCharcater._inventory[i] != NULL)
			_inventory[i] = srcCharcater._inventory[i]->clone();
	}

	for (int i = 0; i < 100; i++)
	{
		if (_floor[i] != NULL)
		{
			delete _floor[i];
			_floor[i] = NULL;
		}
	}

	_name = srcCharcater.getName();
	return *this;
}