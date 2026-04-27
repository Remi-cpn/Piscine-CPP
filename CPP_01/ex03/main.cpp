/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:07:02 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 11:54:31 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#define YELLOW  "\033[33m"

int main(void)
{
	{
		//Test 1.
		std::cout << YELLOW << "Test 1" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		//club.setType(NULL);
		bob.attack();
	}

	std::cout << std::endl;
	
	{
		//Test 2.
		std::cout << YELLOW << "Test 2" << RESET << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(&club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		club.setType("");
		jim.attack();
		jim.setWeapon(NULL);
		jim.attack();
	}
	
	return (0);
}
