/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:34:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/12 15:50:22 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"){
	std::cout << DIM << "DiamondTrap default constructor called" << RESET << std::endl;
	_hitPoints = FragTrap::_hitPointsBegin;
	_energyPoints = ScavTrap::_energyPointsBegin;
	_attackDamage = FragTrap::_attackDamageBegin;
	_name = "";
}
DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"){
	std::cout << DIM << "DiamondTrap name constructor called" << RESET << std::endl;
	_hitPoints = FragTrap::_hitPointsBegin;
	_energyPoints = ScavTrap::_energyPointsBegin;
	_attackDamage = FragTrap::_attackDamageBegin;
	_name = name;
}
DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap){
	std::cout << DIM << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = diamondTrap;
}
DiamondTrap::~DiamondTrap(void){
	std::cout << DIM << "DiamondTrap destructor called" << RESET << std::endl;
}

/* ——— Getters & Setters ———————————————————————————————————————————————————— */
std::string DiamondTrap::getNameDiamond(void) const { return DiamondTrap::_name; }
void		DiamondTrap::setNameDiamond(const std::string &name){ DiamondTrap::_name = name; }


/* ——— Methodes ————————————————————————————————————————————————————————————— */
static void isDead(std::string name){
	std::cout << name << " is DiamondTrap's dead..." << std::endl;
}

void	DiamondTrap::attack(const std::string& target){ ScavTrap::attack(target); }

void	DiamondTrap::whoAmI(void){
	if (_hitPoints <= 0){
		isDead(_name);
		return ;
	}
	
	std::cout << "My name is " << _name << " or " << FragTrap::ClapTrap::_name << "." << std::endl;
}


/* ——— Operator overload ———————————————————————————————————————————————————— */
DiamondTrap& 	DiamondTrap::operator=(const DiamondTrap& srcDiamondTrap){
	ClapTrap::operator=(srcDiamondTrap);
	this->_name = srcDiamondTrap.getNameDiamond();
	return *this;
}