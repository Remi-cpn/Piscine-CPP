/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:13:27 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:49:20 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#define DIM		"\033[2m"
#define RESET	"\033[0m"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5),
	_target("")
{
	std::cout << DIM << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src):
	AForm(src),
	_target(src._target)
{
	std::cout << DIM << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << DIM << "PresidentialPardonForm target constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << DIM << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src) {
	std::cout << DIM << "PresidentialPardonForm assignment operator called" << RESET << std::endl;
	if (this != &src) {
		AForm::operator=(src);
		_target = src._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExecute(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
