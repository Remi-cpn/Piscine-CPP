/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:37:59 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/12 15:25:17 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
FragTrap::FragTrap(void) : ClapTrap(){
	std::cout << DIM << "FragTrap default constructor called" << RESET << std::endl;
	_hitPoints = _hitPointsBegin;
	_energyPoints = _energyPointsBegin;
	_attackDamage = _attackDamageBegin;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
	std::cout << DIM << "FragTrap name constructor called" << RESET << std::endl;
	_hitPoints = _hitPointsBegin;
	_energyPoints = _energyPointsBegin;
	_attackDamage = _attackDamageBegin;
}
FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap){
	std::cout << DIM << "FragTrap copy constructor called" << RESET << std::endl;
	*this = fragTrap;
}
FragTrap::~FragTrap(void){
	std::cout << DIM << "FragTrap destructor called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
static void isDead(std::string name){
	std::cout << name << " is FragTrap's dead..." << std::endl;
}

void	FragTrap::highFivesGuys(void){
	if (_hitPoints <= 0){
		isDead(_name);
		return ;
	}
	
	std::cout << DIM << _name << " asks for a give me five!" << RESET << std::endl;
}



/* ——— Operator overload ———————————————————————————————————————————————————— */
FragTrap& 	FragTrap::operator=(const FragTrap& srcFragTrap){
	ClapTrap::operator=(srcFragTrap);
	return *this;
}