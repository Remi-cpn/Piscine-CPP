/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:42:07 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 15:01:17 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main()
{
	std::cout << YELLOW << "Test 1 : Value found" << RESET << std::endl;
	{
		std::vector<int> vec;
		for (int i = 1; i <= 5; i++)
			vec.push_back(i * 10);

		try
		{
			std::vector<int>::iterator it = easyfind(vec, 30);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 2 : Value not found" << RESET << std::endl;
	{
		std::vector<int> vec;
		for (int i = 1; i <= 5; i++)
			vec.push_back(i * 10);

		try
		{
			std::vector<int>::iterator it = easyfind(vec, 42);
			std::cout << "Found: " << *it << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	return 0;
}
