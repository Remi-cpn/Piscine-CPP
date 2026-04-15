/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:08:38 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/15 14:22:09 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		for (std::string::iterator it = str.begin(); it != str.end(); it++)
			*it = std::toupper(*it);
		std::cout << str;
		if (i < ac - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
