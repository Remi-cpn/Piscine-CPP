/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:28:03 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/08 15:34:33 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

Form::Form():
	_name("..."),
	_signed(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{
	std::cout << DIM << "Form default constructor called" << RESET << std::endl;
}
Form::Form(const Form& srcForm):
	_name(srcForm.getName()),
	_signed(srcForm.getSigned()),
	_gradeRequiredToSign(srcForm.getGradeRequiredToSign()),
	_gradeRequiredToExecute(srcForm.getGradeRequiredToExecute())
{
	std::cout << DIM << "Form copy constructor called" << RESET << std::endl;
	*this = srcForm;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name),
	_signed(false),
	_gradeRequiredToSign(checkGrade(gradeToSign)),
	_gradeRequiredToExecute(checkGrade(gradeToExecute))
{
	std::cout << DIM << "Form name/gradeToSign/gradeToExectute constructor called" << RESET << std::endl;
}
Form::~Form(){
	std::cout << DIM << "Form destructor called" << RESET << std::endl;
}

const std::string& Form::getName() const{ return _name;}
bool	Form::getSigned() const { return _signed;}
int	Form::getGradeRequiredToSign() const{return _gradeRequiredToSign;}
int	Form::getGradeRequiredToExecute() const{return _gradeRequiredToExecute;}


void	Form::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

Form& Form::operator=(const Form& srcForm){
	_signed = srcForm.getSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& form){
	os << form.getName() << ", signed: " << form.getSigned() << ", grade required to sign it is " << form.getGradeRequiredToSign() << ", grade required to execute it is " << form.getGradeRequiredToExecute() << ".";
	return os;
}


int Form::checkGrade(int grade){
	if (grade < 1)
	 	throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	else
		return grade;
}