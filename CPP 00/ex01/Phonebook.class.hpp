/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:11:16 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/16 10:25:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <iostream>

class Contact
{
	public:

		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

		Contact(void);
		~Contact(void);
};

class Phonebook
{
	public:

		Contact list[8];
		
		Phonebook(void);
		~Phonebook(void);

		void	add(void);
		void	search(void);
};

#endif