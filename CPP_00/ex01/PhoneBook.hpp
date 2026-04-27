/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:11:16 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/17 09:20:32 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class Phonebook
{
	public:

		Contact list[8];
		static int _nbContact;
		
		Phonebook(void);
		~Phonebook(void);

		void	add(void);
		void	search(void);
};

#endif