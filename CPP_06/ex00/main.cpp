/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:52:55 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 17:12:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av){
	if (ac != 2) return 1;
	std::string str (av[1]);
	ScalarConverter::convert(str);
	return 0;
}