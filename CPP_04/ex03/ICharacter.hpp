/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:23:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/01 17:01:40 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

class ICharacter
{
	public:
		//Constructors & destructor
		virtual ~ICharacter() { std::cout << DIM << "ICharacter default constructor called" << RESET << std::endl; }
		
		//Member functions
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif