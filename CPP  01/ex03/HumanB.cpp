/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:26:19 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 17:06:16 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */

/* Default constructor. */
HumanB::HumanB(void)
{
	std::cout << DIM << "Default constructor HumanB called" << RESET << std::endl;
}

/* Constructor with name and weapon. */
HumanB::HumanB(std::string name)
{
	std::cout << DIM << "Constructor HumanB called" << RESET << std::endl;
	HumanB::name = name;
}

/* Destructor */
HumanB::~HumanB(void)
{
	std::cout << DIM << "Destructor HumanB called" << RESET << std::endl;
}


/* ——— GETTER & SETTER —————————————————————————————————————————————————————— */

void HumanB::setWeapon(Weapon weapon) { HumanB::weapon = weapon; }


/* ——— Member Function —————————————————————————————————————————————————————— */
void HumanB::attack(void)
{
	std::cout << HumanB::name << " attacks with their " << HumanB::weapon.getType() << std::endl;
}