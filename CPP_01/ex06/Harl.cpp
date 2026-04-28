/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:19:49 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/28 11:08:24 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <map>

/* ——— Constructor & Destructor ————————————————————————————————————————————— */

/* Constructor. */
Harl::Harl(void)
{
	std::cout << DIM << "Default constructor Harl called" << RESET << std::endl;
}

/* Destructor */
Harl::~Harl(void)
{
	std::cout << DIM << "Destructor Harl called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
/* Public */
void Harl::complain(std::string level)
{
	std::map<std::string, int> dispatch;
	dispatch["DEBUG"] = 1;
	dispatch["INFO"] = 2;
	dispatch["WARNING"] = 3;
	dispatch["ERROR"] = 4;
	std::map<std::string, int>::const_iterator it = dispatch.find(level);
	
	if (it == dispatch.end())
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	
	switch(it->second)
	{
		case 1: Harl::debug(); [[fallthrough]];
		case 2: Harl::info(); [[fallthrough]];
		case 3: Harl::warning(); [[fallthrough]];
		case 4:
		{
			Harl::error();
			break ;
		}
	}
}

/* Private */
void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}
