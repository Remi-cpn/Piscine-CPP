/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:02:36 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 14:48:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Zombie::Zombie(void)
{
	std::cout << DIM << "Default constructor called" << RESET << std::endl;
}

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
	
	std::cout << DIM << "Constructor called" << RESET << std::endl;
	std::cout << Zombie::name << " is born !" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << DIM << "Destructor called" << RESET << std::endl;
	std::cout << Zombie::name << " is dead... again." << std::endl;
}



/* ——— Public Methods ——————————————————————————————————————————————————————— */
void	Zombie::announce(void)
{
	std::cout << Zombie::name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
