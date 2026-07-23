/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:44:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/23 17:12:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av){
	
	if (ac < 2 || !argValid(av[1])){
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pm;
	
	pm.algoWithVector(av[1]);
	return 0;
}