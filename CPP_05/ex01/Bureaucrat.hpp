/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 11:20:30 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/08 16:30:03 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Form;

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
		void				signForm(Form& form);

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