/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:13:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:13:12 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};
