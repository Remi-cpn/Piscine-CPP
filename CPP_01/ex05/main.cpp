/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:20:08 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/22 10:19:16 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define YELLOW  "\033[33m"

int main (void)
{
	Harl harl;

	//Test 1.
	std::cout << YELLOW << "Test 1 : DEBUG" << RESET << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl;

	//Test 2.
	std::cout << YELLOW << "Test 2 : INFO" << RESET << std::endl;
	harl.complain("INFO");

	std::cout << std::endl;
	
	//Test 3.
	std::cout << YELLOW << "Test 3 : WARNING" << RESET << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl;

	//Test 4.
	std::cout << YELLOW << "Test 4 : ERROR" << RESET << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl;

	//Test 5.
	std::cout << YELLOW << "Test 5 : Command not found" << RESET << std::endl;
	harl.complain("infdsgdfdh");

	return 0;
}
