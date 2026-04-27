/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:19:49 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 16:48:21 by rcompain         ###   ########.fr       */
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
	std::map<std::string, void(Harl::*)()> dispatch;
	dispatch["debug"] = &Harl::debug;
	dispatch["info"] = &Harl::info;
	dispatch["warning"] = &Harl::warning;
	dispatch["error"] = &Harl::error;
	
	std::map<std::string, void(Harl::*)()>::const_iterator it = dispatch.find(level);
	if (it != dispatch.end())
		(this->*it->second)();
	else
		std::cout << "Command not found" << std::endl;
}

/* Private */
void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. \
I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. \
I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout <<  "This is unacceptable! I want to speak to the manager now." << std::endl;
}
