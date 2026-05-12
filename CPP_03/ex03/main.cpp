/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:26:26 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/12 15:51:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(void)
{
	// Test 1 : Construction chaining (verifie que ClapTrap n'est cree qu'une fois)
	std::cout << YELLOW << "Test 1 : DiamondTrap construction chaining" << RESET << std::endl;
	DiamondTrap dt("Diamond");
	std::cout << std::endl;

	// Test 2 : whoAmI (affiche nom DiamondTrap ET nom ClapTrap)
	std::cout << YELLOW << "Test 2 : whoAmI" << RESET << std::endl;
	dt.whoAmI();
	std::cout << std::endl;

	// Test 3 : Stats initiales (hp=100 FragTrap, ep=50 ScavTrap, ad=30 FragTrap)
	std::cout << YELLOW << "Test 3 : Stats initiales" << RESET << std::endl;
	std::cout << "HP: " << dt.getHP() << std::endl;
	std::cout << "EP: " << dt.getEP() << std::endl;
	std::cout << "AD: " << dt.getAD() << std::endl;
	std::cout << std::endl;

	// Test 4 : attack() (doit utiliser ScavTrap::attack)
	std::cout << YELLOW << "Test 4 : Attack (ScavTrap)" << RESET << std::endl;
	dt.attack("ennemi");
	std::cout << std::endl;

	// Test 5 : Fonctions heritees FragTrap et ScavTrap
	std::cout << YELLOW << "Test 5 : Fonctions heritees" << RESET << std::endl;
	dt.highFivesGuys();
	dt.guardGate();
	std::cout << std::endl;

	// Test 6 : takeDamage et beRepaired
	std::cout << YELLOW << "Test 6 : Damage & repair" << RESET << std::endl;
	dt.takeDamage(40);
	std::cout << "HP apres 40 degats: " << dt.getHP() << std::endl;
	dt.beRepaired(20);
	std::cout << "HP apres repair 20: " << dt.getHP() << std::endl;
	std::cout << std::endl;

	// Test 7 : Copy constructor (verifie que _name DiamondTrap est bien copie)
	std::cout << YELLOW << "Test 7 : Copy constructor" << RESET << std::endl;
	DiamondTrap dt2(dt);
	dt2.whoAmI();
	std::cout << std::endl;

	// Test 8 : Operateur = (verifie que _name DiamondTrap est bien copie)
	std::cout << YELLOW << "Test 8 : Operator =" << RESET << std::endl;
	DiamondTrap dt3("Temp");
	dt3 = dt;
	dt3.whoAmI();
	std::cout << std::endl;

	// Test 9 : Default constructor (ClapTrap name doit etre "_clap_name")
	std::cout << YELLOW << "Test 9 : Default constructor" << RESET << std::endl;
	DiamondTrap dt4;
	dt4.whoAmI();
	std::cout << std::endl;

	// Test 10 : Mort - whoAmI sur un DiamondTrap mort
	std::cout << YELLOW << "Test 10 : whoAmI mort" << RESET << std::endl;
	DiamondTrap dt5("Paul");
	dt5.takeDamage(9999);
	dt5.whoAmI();
	dt5.attack("cible");
	std::cout << std::endl;

	// Test 11 : Destruction chaining (verifie l'ordre inverse des destructeurs)
	std::cout << YELLOW << "Test 11 : Destruction chaining" << RESET << std::endl;

	return (0);
}
