/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:26:26 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 13:26:27 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(void)
{
	//Test 1.
	std::cout << YELLOW << "Test 1 : FragTrap construction chaining" << RESET << std::endl;
	FragTrap ft("Alice");

	std::cout << std::endl;

	//Test 2.
	std::cout << YELLOW << "Test 2 : FragTrap attack" << RESET << std::endl;
	ft.attack("Bob");

	std::cout << std::endl;

	//Test 3.
	std::cout << YELLOW << "Test 3 : highFivesGuys" << RESET << std::endl;
	ft.highFivesGuys();

	std::cout << std::endl;

	//Test 4.
	std::cout << YELLOW << "Test 4 : Take damage & repair" << RESET << std::endl;
	ft.takeDamage(60);
	ft.beRepaired(30);

	std::cout << std::endl;

	//Test 5.
	std::cout << YELLOW << "Test 5 : Die from damage" << RESET << std::endl;
	ft.takeDamage(500);
	ft.attack("Bob");
	ft.highFivesGuys();

	std::cout << std::endl;

	//Test 6.
	std::cout << YELLOW << "Test 6 : Run out of energy" << RESET << std::endl;
	FragTrap ft2("Bob");
	for (int i = 0; i < 101; i++)
		ft2.attack("Alice");

	std::cout << std::endl;

	//Test 7.
	std::cout << YELLOW << "Test 7 : Copy constructor & destruction chaining" << RESET << std::endl;
	FragTrap ft3(ft2);
	ft3.attack("Alice");

	std::cout << std::endl;

	//Test 8.
	std::cout << YELLOW << "Test 8 : ClapTrap vs ScavTrap vs FragTrap attacks" << RESET << std::endl;
	ClapTrap ct("ClapTrap");
	ScavTrap st("ScavTrap");
	ct.attack("target");
	st.attack("target");
	ft2.attack("target");

	return (0);
}
