/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:17:30 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 12:26:29 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

#define DIM		"\033[2m"
#define RESET   "\033[0m"


Base::~Base() {
	std::cout << DIM << "Base destructor called" << RESET << std::endl;
}

Base* generate(void)
{
	switch (std::rand() % 3){
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C." << std::endl;
	else
		std::cout << "Invalid type." << std::endl;
}

void identify(Base& p)
{
	Base res;
	try{
		res = dynamic_cast<A&>(p);
		std::cout << "Type is A." << std::endl;
		return;
	}
	catch (std::exception&) {}
	try{
		res = dynamic_cast<B&>(p);
		std::cout << "Type is B." << std::endl;
		return;
	}
	catch (std::exception&) {}
	try{
		res = dynamic_cast<C&>(p);
		std::cout << "Type is C." << std::endl;
		return;
	}
	catch (std::exception&) {}
	std::cout << "Invalid type." << std::endl;
}
