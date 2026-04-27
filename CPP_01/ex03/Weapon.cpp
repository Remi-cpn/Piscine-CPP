/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:09 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 11:59:43 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */

/* Default constructor. */
Weapon::Weapon(void)
{
	std::cout << DIM << "Default constructor Weapon called" << RESET << std::endl;
}

/* Constructor with type. */
Weapon::Weapon(std::string type)
{
	std::cout << DIM << "Constructor Weapon called" << RESET << std::endl;
	Weapon::_type = type;
}

/* Destructor */
Weapon::~Weapon(void)
{
	std::cout << DIM << "Destructor Weapon called" << RESET << std::endl;
}


/* ——— GETTER & SETTER —————————————————————————————————————————————————————— */

std::string const& Weapon::getType(void) { return Weapon::_type; }
void Weapon::setType(std::string type) { Weapon::_type = type; }