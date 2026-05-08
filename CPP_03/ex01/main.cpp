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

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main(void)
{
	//Test 1.
	std::cout << YELLOW << "Test 1 : Construction chaining" << RESET << std::endl;
	ScavTrap st("Bob");

	std::cout << std::endl;

	//Test 2.
	std::cout << YELLOW << "Test 2 : ScavTrap attack (different message)" << RESET << std::endl;
	st.attack("Alice");

	std::cout << std::endl;

	//Test 3.
	std::cout << YELLOW << "Test 3 : guardGate" << RESET << std::endl;
	st.guardGate();

	std::cout << std::endl;

	//Test 4.
	std::cout << YELLOW << "Test 4 : Take damage & repair" << RESET << std::endl;
	st.takeDamage(50);
	st.beRepaired(20);

	std::cout << std::endl;

	//Test 5.
	std::cout << YELLOW << "Test 5 : Die from damage" << RESET << std::endl;
	st.takeDamage(200);
	st.attack("Alice");
	st.guardGate();

	std::cout << std::endl;

	//Test 6.
	std::cout << YELLOW << "Test 6 : Run out of energy" << RESET << std::endl;
	ScavTrap st2("Eve");
	for (int i = 0; i < 51; i++)
		st2.attack("Bob");

	std::cout << std::endl;

	//Test 7.
	std::cout << YELLOW << "Test 7 : Copy constructor & destruction chaining" << RESET << std::endl;
	ScavTrap st3(st2);
	st3.attack("Bob");

	std::cout << std::endl;

	//Test 8.
	std::cout << YELLOW << "Test 8 : ClapTrap vs ScavTrap (different attack messages)" << RESET << std::endl;
	ClapTrap ct("ClapTrap");
	ct.attack("target");
	st2.attack("target");

	return (0);
}
