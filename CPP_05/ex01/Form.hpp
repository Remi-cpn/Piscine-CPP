/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:28:14 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/08 15:31:58 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form& srcForm);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		~Form();

		Form& operator=(const Form& srcForm);

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;
		
		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw () { return "Grade too high !"; }
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw () { return "Grade too low !"; }
		};

	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;

		static int checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif