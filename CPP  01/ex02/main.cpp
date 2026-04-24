/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:07:02 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 16:21:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define YELLOW  "\033[33m\033[2m"
#define RESET   "\033[0m"

int main(void)
{
	std::string s = "HI THIS IS BRAIN";
	std::string* stringPTR = &s;
	std::string& stringREF = s;

	//Test 1:
	std::cout << YELLOW << "Test 1" << RESET << std::endl;
	std::cout << "The memory address of s = " << &s << std::endl;
	std::cout << "The memory address of stringPTR = " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF = " << &stringREF << std::endl;

	std::cout << std::endl;
	
	//Test 2:
	std::cout << YELLOW << "Test 2" << RESET << std::endl;
	std::cout << "The value of s = " << s << std::endl;
	std::cout << "The value pointed to by stringPTR = " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF = " << stringREF << std::endl;

	return (0);
}
