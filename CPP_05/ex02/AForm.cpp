/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:11:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:30:32 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

AForm::AForm():
	_name("..."),
	_signed(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{
	std::cout << DIM << "AForm default constructor called" << RESET << std::endl;
}
AForm::AForm(const AForm& srcAForm):
	_name(srcAForm.getName()),
	_signed(srcAForm.getSigned()),
	_gradeRequiredToSign(srcAForm.getGradeRequiredToSign()),
	_gradeRequiredToExecute(srcAForm.getGradeRequiredToExecute())
{
	std::cout << DIM << "AForm copy constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute):
	_name(name),
	_signed(false),
	_gradeRequiredToSign(checkGrade(gradeToSign)),
	_gradeRequiredToExecute(checkGrade(gradeToExecute))
{
	std::cout << DIM << "AForm name/gradeToSign/gradeToExectute constructor called" << RESET << std::endl;
}
AForm::~AForm(){
	std::cout << DIM << "AForm destructor called" << RESET << std::endl;
}

const std::string& AForm::getName() const{ return _name;}
bool	AForm::getSigned() const { return _signed;}
int	AForm::getGradeRequiredToSign() const{return _gradeRequiredToSign;}
int	AForm::getGradeRequiredToExecute() const{return _gradeRequiredToExecute;}


void	AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

AForm& AForm::operator=(const AForm& srcAForm){
	_signed = srcAForm.getSigned();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& aForm){
	os << aForm.getName() << ", signed: " << aForm.getSigned() << ", grade required to sign it is " << aForm.getGradeRequiredToSign() << ", grade required to execute it is " << aForm.getGradeRequiredToExecute() << ".";
	return os;
}


int AForm::checkGrade(int grade){
	if (grade < 1)
	 	throw AForm::GradeTooHighException();
	else if (grade > 150)
		throw AForm::GradeTooLowException();
	else
		return grade;
}

void AForm::checkExecute(Bureaucrat const & executor) const {
    if (!_signed)
        throw AForm::NotSignedException();
    if (executor.getGrade() > _gradeRequiredToExecute)
        throw AForm::GradeTooLowException();
}