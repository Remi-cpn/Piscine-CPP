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

bool checkDate(std::string &date){
	int count = 0;
	for (std::string::iterator it = date.begin(); it != date.end(); count++, it++){
		if (count > 14)
			return false;
		if ((count == 4 || count == 7) && *it != ',')
			return false;
		else if (!std::isdigit((*it))){
			return false;
		}
	}
	return true;
}

int main(int ac, char **av){
	
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange b;

	std::string fileName(av[1]);
	std::ifstream file(fileName);
	std::string line;
	while (getline(file, line)){
		std::string date;
		std::string::iterator it = line.begin();
		for (; *it != ',' && it != line.end(); it++){
			date.push_back(*it);
		}
		if (!checkDate(date)){
			std::cout << "date not valid." << std::endl;
			return 1;
		}
		if (it == line.end()){
			std::cout << "data.csv not valid." << std::endl;
			return 1;
		}
		it++;

		std::string priceString = 0;
		for (; it != line.end(); it++){
			priceString.push_back(*it);
		}
		float price = std::stof(priceString);
		
		b.addData(date, price);
	}


	return 0;
}