/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:25:13 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 10:24:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "whatever.hpp"
# include <iostream>
# include <string>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main (){

	// Test 1 : Swap
	std::cout << YELLOW << "Test 1 : Swap" << RESET << std::endl;
	{
		int i = 42, j = 84;

		::swap(i, j);
		std::cout << "i = " << i << std::endl;
		std::cout << "j = " << j << std::endl;

		std::string s1 = "foo", s2 = "bar";

		::swap(s1, s2);
		std::cout << "s1 = " << s1 << std::endl;
		std::cout << "s2 = " << s2 << std::endl;
	}

	std::cout << std::endl;

	// Test 2 : Min
	std::cout << YELLOW << "Test 2 : Min" << RESET << std::endl;
	{
		int i = 42, j = 84;

		std::cout << ::min(i, j) << std::endl;

		std::string s1 = "foo", s2 = "bar";

		std::cout << ::min(s1, s2) << std::endl;
	}

	std::cout << std::endl;

	// Test 3 : Max
	std::cout << YELLOW << "Test 3 : Max" << RESET << std::endl;
	{
		int i = 42, j = 84;

		std::cout << ::max(i, j) << std::endl;

		std::string s1 = "foo", s2 = "bar";

		std::cout << ::max(s1, s2) << std::endl;
	}

	// Test 4 : Test du sujet
	std::cout << YELLOW << "Test 4 : Test du sujet" << RESET << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}