/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 10:19:18 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/09 10:22:13 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		~Intern();

		Intern&	operator=(const Intern& src);

		AForm*	makeForm(std::string formName, std::string target);
};