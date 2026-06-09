/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:11:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:30:04 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm& srcAForm);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		AForm& operator=(const AForm& srcAForm);

		const std::string&	getName() const;
		bool				getSigned() const;
		int					getGradeRequiredToSign() const;
		int					getGradeRequiredToExecute() const;
		
		void				beSigned(const Bureaucrat& bureaucrat);
		virtual void 		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				const char* what() const throw () { return "Grade too high !"; }
		};

		class GradeTooLowException: public std::exception{
			public:
				const char* what() const throw () { return "Grade too low !"; }
		};

		class NotSignedException: public std::exception{
			public:
				const char* what() const throw () { return "Can't be executed !"; }
		};

	protected:
		void				checkExecute(Bureaucrat const & executor) const;

	private:
		const std::string _name;
		bool _signed;
		const int _gradeRequiredToSign;
		const int _gradeRequiredToExecute;

		static int checkGrade(int grade);
};

std::ostream& operator<<(std::ostream& os, const AForm& aForm);

#endif