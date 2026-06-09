/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:30 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:58:49 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& srcBureaucrat);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& srcBureaucrat);

		const std::string&	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);

		void				increaseGrade();
		void				decreaseGrade();
		void				signForm(AForm& aForm);
		void				executeForm(AForm const & form) const;

		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw () { return "Grade too high !"; }
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw () { return "Grade too low !"; }
		};
		
	private:
		const std::string 	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif