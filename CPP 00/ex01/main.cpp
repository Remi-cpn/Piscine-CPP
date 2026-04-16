/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:25:40 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/16 10:42:12 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

int	main(void)
{
	Phonebook phonebook;
	std::string str;

	while (std::getline(std::cin, str))
	{
		if (str == "ADD")
			phonebook.add();
		if (str == "SEARCH")
			phonebook.search();
		if (str == "EXIT")
			break ;
	}
	return 0;
}
