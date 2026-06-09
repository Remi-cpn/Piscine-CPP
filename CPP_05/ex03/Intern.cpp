/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:19:34 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 10:36:23 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

Intern::Intern() {
	std::cout << DIM << "Intern default constructor called" << RESET << std::endl;
}
Intern::Intern(const Intern& src) { 
	std::cout << DIM << "Intern copy constructor called" << RESET << std::endl;
	*this = src; 
}
Intern::~Intern() {
	std::cout << DIM << "Intern destructor called" << RESET << std::endl;
}
Intern& Intern::operator=(const Intern& src){ 
	(void)src; 
	return *this; 
}

AForm*	Intern::makeForm(std::string formName, std::string target){
	std::map<std::string, int> dispatch;
	dispatch["PresidentialPardonForm"] = 1;
	dispatch["RobotomyRequestForm"] = 2;
	dispatch["ShrubberyCreationForm"] = 3;
	std::map<std::string, int>::const_iterator it = dispatch.find(formName);
	
	if (it == dispatch.end())
	{
		std::cout << "I don't find the formulary..." << std::endl;
		return NULL;
	}
	
	std::cout << "Intern creates " << formName << std::endl;
	switch(it->second)
	{
		case 1: return new PresidentialPardonForm(target);
		case 2: return new RobotomyRequestForm(target);
		case 3: return new ShrubberyCreationForm(target);
	}
	return NULL;
}