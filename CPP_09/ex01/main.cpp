/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:54:09 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/16 08:16:19 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

int main (int ac, char **av){
	
	if (ac != 2){
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN rpn;
	int toggle = -1;
	bool needSpace = false;
	std::string valid = "+-/*";
	
	for (int i = 0; av[1][i]; i++){

		char c = av[1][i];

		if (c == ' '){
			needSpace = false;
			continue;
		}
		
		if (std::isdigit(c) && !needSpace){
			toggle++;
			needSpace = true;
			rpn.addNewDigit(c - '0');
		}
		else if (valid.find(c) != std::string::npos && !needSpace){
			toggle--;
			needSpace = true;
			if (rpn.doOperator(c) == -1){
				std::cerr << "Error" << std::endl;
				return 1;
			}
		}
		else{
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}

	if (toggle != 0){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	
	std::cout << rpn.takeLastDigit() << std::endl;

	return 0;
}