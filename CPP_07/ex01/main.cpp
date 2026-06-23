/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:29:41 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 11:01:09 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

void	printInt(const int& n)
{
	std::cout << n << " ";
}

void	printString(const std::string& s)
{
	std::cout << s << " ";
}

void	toUpperString(std::string& s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = std::toupper(s[i]);
}

int main (){
	// Test 1 : Int
	std::cout << YELLOW << "Test 1 : Int" << RESET << std::endl;
	{
		int		tab[] = {1, 2, 3, 4, 5};
		size_t	size = 5;

		::iter(tab, size, printInt);
		std::cout << std::endl;
	}

	std::cout << std::endl;

	// Test 3 : String
	std::cout << YELLOW << "Test 3 : String" << RESET << std::endl;
	{
		std::string	tab[] = {"hello", "world", "42"};
		size_t		size = 3;

		::iter(tab, size, printString);
		std::cout << std::endl;

		::iter(tab, size, toUpperString);
		::iter(tab, size, printString);
		std::cout << std::endl;
	}

	return 0;
}