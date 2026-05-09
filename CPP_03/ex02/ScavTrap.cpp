/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:22:16 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/09 14:39:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
ScavTrap::ScavTrap(void) : ClapTrap(){
	std::cout << DIM << "ScavTrap default constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
	std::cout << DIM << "ScavTrap name constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap){
	std::cout << DIM << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = scavTrap;
}
ScavTrap::~ScavTrap(void){
	std::cout << DIM << "ScavTrap destructor called" << RESET << std::endl;
}


/* ——— Methodes ————————————————————————————————————————————————————————————— */
static void isDead(std::string name){
	std::cout << name << " is ScavTrap's dead..." << std::endl;
}

void 	ScavTrap::guardGate(){
	
	if (_hitPoints <= 0){
		isDead(_name);
		return ;
	}
	
	std::cout << ClapTrap::getName() << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	
	if (_hitPoints <= 0){
		isDead(_name);
		return ;
	}

	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << _name << " attacks "<< target << ", causing " << _attackDamage << " ScavTrap's points of damage!" << std::endl;
	}
	else
		std::cout << _name << " low ScavTrap's energy."<< std::endl;	
}


/* ——— Operator overload ———————————————————————————————————————————————————— */
ScavTrap& 	ScavTrap::operator=(const ScavTrap& srcScavTrap){
	ClapTrap::operator=(srcScavTrap);
	return *this;
}