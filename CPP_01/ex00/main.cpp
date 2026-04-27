/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:07:02 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 14:55:09 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	//Test 1: Stack.
	std::cout << YELLOW << "Test 1" << RESET << std::endl;
	randomChump("Paul");

	std::cout << std::endl;
	
	//Test 2: Heap.
	std::cout << YELLOW << "Test 2" << RESET << std::endl;
	Zombie* z = newZombie("Heap Bob");
	z->announce();
	delete z;
	return (0);
}