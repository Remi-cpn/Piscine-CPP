/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:09:43 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/01 18:16:51 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Ice::Ice(void): AMateria()
{
	std::cout << DIM << "Ice default constructor called" << RESET << std::endl;
	_type = "ice";
}
Ice::Ice(const Ice& srcIce): AMateria(srcIce)
{
	std::cout << DIM << "Ice copy constructor called" << RESET << std::endl;
}
Ice::~Ice(void)
{
	std::cout << DIM << "Ice destructor called" << RESET << std::endl;
}


/* ——— Methodes ————————————————————————————————————————————————————————————— */
AMateria*	Ice::clone() const
{
	Ice *newIce = new Ice(*this);
	return newIce;
}
void	Ice::use(ICharacter& target)
{
	std::cout << "*Ice shoots an ice bolt at " << target.getName() <<  " *" << std::endl;
}

/* ——— Operator overload ———————————————————————————————————————————————————— */
Ice& Ice::operator=(const Ice& srcIce)
{
	_type = srcIce.getType();
	return *this;
}