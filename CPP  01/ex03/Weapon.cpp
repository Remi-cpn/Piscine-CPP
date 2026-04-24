/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:09 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 17:06:52 by rcompain         ###   ########.fr       */
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
	Weapon::type = type;
}

/* Destructor */
Weapon::~Weapon(void)
{
	std::cout << DIM << "Destructor Weapon called" << RESET << std::endl;
}


/* ——— GETTER & SETTER —————————————————————————————————————————————————————— */

std::string const& Weapon::getType(void) { return Weapon::type; }
void Weapon::setType(std::string type) { Weapon::type = type; }