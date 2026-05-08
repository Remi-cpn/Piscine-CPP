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

#include "ClapTrap.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(void)
{
	ClapTrap ct("Bob");

	//Test 1.
	std::cout << YELLOW << "Test 1 : Attack" << RESET << std::endl;
	ct.attack("Alice");

	std::cout << std::endl;

	//Test 2.
	std::cout << YELLOW << "Test 2 : Take damage & repair" << RESET << std::endl;
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << std::endl;

	//Test 3.
	std::cout << YELLOW << "Test 3 : Die from damage" << RESET << std::endl;
	ct.takeDamage(20);
	ct.attack("Alice");
	ct.beRepaired(5);

	std::cout << std::endl;

	//Test 4.
	std::cout << YELLOW << "Test 4 : Run out of energy" << RESET << std::endl;
	ClapTrap ct2("Eve");
	for (int i = 0; i < 11; i++)
		ct2.attack("Bob");

	std::cout << std::endl;

	//Test 5.
	std::cout << YELLOW << "Test 5 : Copy constructor" << RESET << std::endl;
	ClapTrap ct3(ct2);
	ct3.attack("Bob");

	return (0);
}
