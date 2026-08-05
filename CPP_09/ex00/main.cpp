/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:14:06 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/09 13:26:35 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **av){

	if (ac != 2){
		std::cout << "Error" << std::endl;
		return 1;
	}

	std::ifstream file(av[1]);
	if (!file.is_open()){
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try{
		BitcoinExchange btc("data.csv");

		std::string line;
		while (std::getline(file, line)){
			std::string output = btc.evaluateLine(line);
			if (!output.empty())
				std::cout << output << std::endl;
		}
	}
	catch (const std::exception &e){
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
