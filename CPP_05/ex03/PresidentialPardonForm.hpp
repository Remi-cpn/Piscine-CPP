/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 09:13:41 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 09:40:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};
