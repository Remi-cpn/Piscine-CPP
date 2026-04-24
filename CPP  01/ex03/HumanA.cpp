/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:26:01 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 17:06:22 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */

/* Default constructor. */
HumanA::HumanA(void)
{
	std::cout << DIM << "Default constructor HumanA called" << RESET << std::endl;
}

/* Constructor with name and weapon. */
HumanA::HumanA(std::string name, Weapon weapon)
{
	std::cout << DIM << "Constructor HumanA called" << RESET << std::endl;
	HumanA::name = name;
	HumanA::weapon = weapon;
}

/* Destructor */
HumanA::~HumanA(void)
{
	std::cout << DIM << "Destructor HumanA called" << RESET << std::endl;
}

/* ——— Member Function —————————————————————————————————————————————————————— */
void HumanA::attack(void)
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon.getType() << std::endl;
}