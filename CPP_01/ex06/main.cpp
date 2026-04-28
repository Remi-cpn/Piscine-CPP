/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:20:08 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/28 11:07:30 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define YELLOW  "\033[33m"

int main (int ac, char **av)
{
	if (ac != 2)
		return 1;

	Harl harl;
		
	harl.complain(std::string(av[1]));
	return 0;
}
