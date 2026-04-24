/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:07:02 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 15:25:38 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//Test 1.
	std::cout << YELLOW << "Test 1" << RESET << std::endl;
	Zombie* z = zombieHorde(1, "Paul");
	z->announce();
	delete[] z;

	std::cout << std::endl;
	
	//Test 2.
	std::cout << YELLOW << "Test 2" << RESET << std::endl;
	Zombie* h = zombieHorde(10, "Paul");
	for (int i = 0; i < 10; i++)
		h[i].announce();
	delete[] h;
	
	return (0);
}
