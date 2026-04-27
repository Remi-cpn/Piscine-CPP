/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:26:01 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 11:57:30 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */

/* Constructor with name and weapon. */
HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	std::cout << DIM << "Constructor HumanA called" << RESET << std::endl;
	HumanA::_name = name;
}

/* Destructor */
HumanA::~HumanA(void)
{
	std::cout << DIM << "Destructor HumanA called" << RESET << std::endl;
}

/* ——— Member Function —————————————————————————————————————————————————————— */
void HumanA::attack(void)
{
	std::cout << HumanA::_name << " attacks with their " << HumanA::_weapon.getType() << std::endl;
}