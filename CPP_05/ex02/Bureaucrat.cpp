/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:22 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 10:03:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

Bureaucrat::Bureaucrat(): _name("..."), _grade(150){
	std::cout << DIM << "Bureaucrat default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& srcBureaucrat): _name(srcBureaucrat.getName()){
	std::cout << DIM << "Bureaucrat copy constructor called" << RESET << std::endl;
	*this = srcBureaucrat;
}
		
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
	std::cout << DIM << "Bureaucrat name/grade constructor called" << RESET << std::endl;
	setGrade(grade);
}

Bureaucrat::~Bureaucrat(){
	std::cout << DIM << "Bureaucrat destructor called" << RESET << std::endl;
}

const std::string&	Bureaucrat::getName() const{ return _name;}
int					Bureaucrat::getGrade() const{ return _grade;}
void				Bureaucrat::setGrade(int grade){
	
	if (grade < 1)
	 	throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

void	Bureaucrat::increaseGrade(){ setGrade(getGrade() - 1);}
void	Bureaucrat::decreaseGrade(){ setGrade(getGrade() + 1);}

void	Bureaucrat::signForm(AForm& aForm){
	try {
		aForm.beSigned(*this);
		std::cout << getName() << " signed " << aForm.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << getName() << " couldn't sign " << aForm.getName() << " because " << e.what() << std::endl;
	}
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& srcBureaucrat){
	this->_grade = srcBureaucrat.getGrade();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}

void	Bureaucrat::executeForm(AForm const & form) const{
	try{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}