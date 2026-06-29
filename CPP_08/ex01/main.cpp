/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:04:52 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/29 12:41:13 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main()
{
	std::cout << YELLOW << "Test 1 : Subject example" << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 2 : addNumber on a full Span throws" << RESET << std::endl;
	{
		Span sp = Span(2);
		try
		{
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			std::cout << "No exception (unexpected)" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 3 : span on empty or single-element Span throws" << RESET << std::endl;
	{
		Span sp = Span(5);
		try
		{
			sp.shortestSpan();
			std::cout << "No exception (unexpected)" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		sp.addNumber(42);
		try
		{
			sp.longestSpan();
			std::cout << "No exception (unexpected)" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 4 : fill with a range of iterators" << RESET << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(6);
		vec.push_back(3);
		vec.push_back(17);
		vec.push_back(9);
		vec.push_back(11);

		Span sp = Span(5);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	std::cout << YELLOW << "Test 5 : 10 000 numbers via range insertion" << RESET << std::endl;
	{
		std::vector<int> vec;
		for (int i = 0; i < 10000; i++)
			vec.push_back(std::rand());

		Span sp = Span(10000);
		sp.addNumber(vec.begin(), vec.end());
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;
	}

	return 0;
}
