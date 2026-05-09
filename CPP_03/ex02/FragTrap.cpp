/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:37:59 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/09 14:47:02 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
FragTrap::FragTrap(void) : ClapTrap(){
	std::cout << DIM << "FragTrap default constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name){
	std::cout << DIM << "FragTrap name constructor called" << RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
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