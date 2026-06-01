/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:18:22 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/01 18:17:29 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
AMateria::AMateria(void)
{
	std::cout << DIM << "AMateria default constructor called" << RESET << std::endl;
}
AMateria::AMateria(const AMateria& srcAMateria)
{
	std::cout << DIM << "AMateria copy constructor called" << RESET << std::endl;
	*this = srcAMateria;
}
AMateria::AMateria(std::string const & type)
{
	std::cout << DIM << "AMateria type constructor called" << RESET << std::endl;
	_type = type;
}
AMateria::~AMateria(void)
{
	std::cout << DIM << "AMateria destructor called" << RESET << std::endl;
}


/* ——— Getters & Setters ———————————————————————————————————————————————————— */
std::string const& AMateria::getType() const { return _type; }
void	AMateria::setType(const std::string type) { _type = type; }

void 	AMateria::use(ICharacter& target){}


/* ——— Operator overload ———————————————————————————————————————————————————— */
AMateria& AMateria::operator=(const AMateria& srcAMateria)
{
	_type = srcAMateria.getType();
	return *this;
}