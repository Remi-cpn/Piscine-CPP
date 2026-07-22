/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:44:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/21 22:32:10 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av){
	
	if (ac < 2 || !argValid(av)){
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pm(&av[1]);
	

	std::vector<int, int> v = pm.getVectorStack();
	for (std::vector<int, int>::const_iterator it = v.cbegin(); it != v.cend(); it++){
		std::cout << it->second;
	}
	std::cout << std::endl;
}