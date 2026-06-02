/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 12:10:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:48:10 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Cure::Cure(void): AMateria()
{
	std::cout << DIM << "Cure default constructor called" << RESET << std::endl;
	_type = "cure";
}
Cure::Cure(const Cure& srcCure): AMateria(srcCure)
{
	std::cout << DIM << "Cure copy constructor called" << RESET << std::endl;
}
Cure::~Cure(void)
{
	std::cout << DIM << "Cure destructor called" << RESET << std::endl;
}


/* ——— Methodes ————————————————————————————————————————————————————————————— */
AMateria*	Cure::clone() const
{
	Cure *newCure = new Cure(*this);
	return newCure;
}
void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() <<  "'s wounds *" << std::endl;
}