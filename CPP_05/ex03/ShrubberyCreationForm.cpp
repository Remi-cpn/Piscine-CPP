/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:12:15 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:47:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137),
	_target("")
{
	std::cout << DIM << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src):
	AForm(src),
	_target(src._target)
{
	std::cout << DIM << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << DIM << "ShrubberyCreationForm target constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << DIM << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
	std::cout << DIM << "ShrubberyCreationForm assignment operator called" << RESET << std::endl;
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecute(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "       *       \n";
	file << "      ***      \n";
	file << "     *****     \n";
	file << "    *******    \n";
	file << "   *********   \n";
	file << "      |||      \n";
}
