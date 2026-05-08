/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:37:36 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 11:09:03 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#define YELLOW  "\033[33m"

int main( void )
{
	Point a(0, 0);
	Point b(4, 0);
	Point c(0, 4);

	//Test 1.
	std::cout << YELLOW << "Test 1 :" << RESET << std::endl;
	std::cout << "Inside:   " << bsp(a, b, c, Point(1, 1)) << std::endl;
	
	//Test 2.
	std::cout << YELLOW << "Test 2 :" << RESET << std::endl;
	std::cout << "Outside:  " << bsp(a, b, c, Point(3, 3)) << std::endl;

	//Test 3.
	std::cout << YELLOW << "Test 3 :" << RESET << std::endl;
	std::cout << "Vertex:   " << bsp(a, b, c, Point(0, 0)) << std::endl;

	//Test 4.
	std::cout << YELLOW << "Test 4 :" << RESET << std::endl;
	std::cout << "On edge:  " << bsp(a, b, c, Point(2, 0)) << std::endl;
}
