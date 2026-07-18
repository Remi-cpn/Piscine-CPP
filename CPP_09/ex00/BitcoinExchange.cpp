/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:14:25 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/09 13:25:47 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

BitcoinExchange::BitcoinExchange(){
	std::cout << DIM << "BitcoinExchange default constructor called" << RESET << std::endl;
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){
	std::cout << DIM << "BitcoinExchange copy constructor called" << RESET << std::endl;
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src){
	
}
BitcoinExchange::~BitcoinExchange(){
	std::cout << DIM << "BitcoinExchange destructor called" << RESET << std::endl;
}


void BitcoinExchange::addData(std::string date, float price){
	data[date] = price;
}