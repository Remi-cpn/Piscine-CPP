/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:13:02 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:57:56 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

#define DIM		"\033[2m"
#define RESET	"\033[0m"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::srand(std::time(NULL));
	std::cout << DIM << "RobotomyRequestForm target constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << DIM << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecute(executor);
	std::cout << "DRRRRRRRR DRRRRRR..." << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " robotomy failed." << std::endl;
}
