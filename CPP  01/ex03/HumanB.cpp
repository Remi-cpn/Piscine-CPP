/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:26:19 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 11:58:46 by rcompain         ###   ########.fr       */
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
	HumanB::_name = name;
}

/* Destructor */
HumanB::~HumanB(void)
{
	std::cout << DIM << "Destructor HumanB called" << RESET << std::endl;
}


/* ——— GETTER & SETTER —————————————————————————————————————————————————————— */

void HumanB::setWeapon(Weapon* weapon) { HumanB::_weapon = weapon; }


/* ——— Member Function —————————————————————————————————————————————————————— */
void HumanB::attack(void)
{
	if (!HumanB::_weapon)
	{
		std::cout << HumanB::_name << " has no weapon!" << std::endl;
		return ;
	}
	std::cout << HumanB::_name << " attacks with their " << HumanB::_weapon->getType() << std::endl;
}