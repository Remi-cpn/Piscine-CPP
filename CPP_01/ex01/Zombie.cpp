/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:02:36 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 15:24:55 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
/* Default constructor. */
Zombie::Zombie(void)
{
	std::cout << DIM << "Default constructor called" << RESET << std::endl;
}

/* Destructor. */
Zombie::~Zombie(void)
{
	std::cout << DIM << "Destructor called" << RESET << std::endl;
	std::cout << Zombie::name << " is dead... again." << std::endl;
}

/* Setter name.*/
void	Zombie::setName(std::string name) { Zombie::name = name; }


/* ——— Public Methods ——————————————————————————————————————————————————————— */
/* Print name + ":  BraiiiiiiinnnzzzZ..." */
void	Zombie::announce(void)
{
	std::cout << Zombie::name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
