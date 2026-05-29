/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:26:05 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/29 09:29:39 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
ClapTrap::ClapTrap(void): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << DIM << "ClapTrap default constructor called" << RESET << std::endl;
}
ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << DIM << "ClapTrap name constructor called" << RESET << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& clapTrap){
	std::cout << DIM << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = clapTrap;
}
ClapTrap::~ClapTrap(void){
	std::cout << DIM << "ClapTrap destructor called" << RESET << std::endl;
}



/* ——— Getters & Setters ———————————————————————————————————————————————————— */
int			ClapTrap::getHP(void) const { return _hitPoints; }
int			ClapTrap::getEP(void) const { return _energyPoints; }
int			ClapTrap::getAD(void) const { return _attackDamage; }
std::string ClapTrap::getName(void) const { return _name; }
void		ClapTrap::setName(const std::string &name){ _name = name; }
void		ClapTrap::setHP(int hitPoints){ _hitPoints = hitPoints; }
void		ClapTrap::setEP(int energyPoints){ _energyPoints = energyPoints; }
void		ClapTrap::setAD(int attackDamage){ _attackDamage = attackDamage; }



/* ——— Methodes ————————————————————————————————————————————————————————————— */
static void isDead(std::string name){
	std::cout << name << " is dead..." << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	
	if (_hitPoints <= 0){
		isDead(_name);
		return ;
	}

	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << _name << " attacks "<< target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << _name << " low energy."<< std::endl;	
}

void 	ClapTrap::takeDamage(unsigned int amount){
	
	if (_hitPoints <= 0){
		std::cout << _name << " is already dead..." << std::endl;
		return ;
	}
	
	_hitPoints -= amount;
	std::cout << _name << " take "<< amount << " damage. " << std::endl;
	
	if (_hitPoints <= 0){ isDead(_name); }
}

void	ClapTrap::beRepaired(unsigned int amount){
	
	if (_hitPoints <= 0){
		isDead(_name);
		return ;
	}
	
	if (_energyPoints > 0) {
		_energyPoints--;
		std::cout << _name << " regains " << amount << " hit points." << std::endl;
		_hitPoints += amount;
	}
	else
		std::cout << _name << " low energy."<< std::endl;

}


/* ——— Operator overload ———————————————————————————————————————————————————— */
ClapTrap& 	ClapTrap::operator=(const ClapTrap& srcClapTrap){
	_name = srcClapTrap.getName();
	_hitPoints = srcClapTrap.getHP();
	_energyPoints = srcClapTrap.getEP();
	_attackDamage = srcClapTrap.getAD();
	return *this;
}