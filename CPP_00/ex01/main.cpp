/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:25:40 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/17 08:46:35 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	Phonebook phonebook;
	std::string str;

	while (std::getline(std::cin, str))
	{
		if (str == "ADD")
			phonebook.add();
		else if (str == "SEARCH")
			phonebook.search();
		else if (str == "EXIT")
			break ;
	}
	if (std::cin.eof())
		return 1;
	return 0;
}
