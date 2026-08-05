/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:14:25 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/05 13:12:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

#define DIM		"\033[2m"
#define RESET   "\033[0m"


BitcoinExchange::BitcoinExchange(){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}
BitcoinExchange::BitcoinExchange(const std::string &filename){
	std::cout << DIM << "Constructor called." << RESET << std::endl;
	loadDatabase(filename);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
	*this = src;
}
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src){
	if (this != &src)
		_data = src._data;
	return *this;
}
BitcoinExchange::~BitcoinExchange(){
	std::cout << DIM << "Destructor called." << RESET << std::endl;
}

// ——— Utils Parsing ———————————————————————————————————————————————————————————————

static std::string	trim(const std::string &s){
	size_t start = s.find_first_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = s.find_last_not_of(" \t\r\n");
	return s.substr(start, end - start + 1);
}

static bool	splitLine(const std::string &line, char sep, std::string &left, std::string &right){
	size_t pos = line.find(sep);
	if (pos == std::string::npos)
		return false;
	left = trim(line.substr(0, pos));
	right = trim(line.substr(pos + 1));
	return true;
}

// ——— Utils Validation ——————————————————————————————————————————————————————————————

static bool	isValidDate(const std::string &date){
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); i++){
		if (i == 4 || i == 7)
			continue;
		unsigned char c = static_cast<unsigned char>(date[i]);
		if (!std::isdigit(c))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12 || day < 1)
		return false;
	int maxDay = daysInMonth[month - 1];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		maxDay = 29;
	return day <= maxDay;
}

static bool	parseValue(const std::string &valueStr, double &value){
	if (valueStr.empty())
		return false;
	std::istringstream iss(valueStr);
	iss >> value;
	if (iss.fail())
		return false;
	std::string rest;
	if (iss >> rest)
		return false;
	return true;
}

// ——— Database ——————————————————————————————————————————————————————————————————

void	BitcoinExchange::loadDatabase(const std::string &filename){
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string rawLine;
	std::getline(file, rawLine);
	while (std::getline(file, rawLine)){
		std::string line = trim(rawLine);
		if (line.empty())
			continue;
		std::string date, rateStr;
		if (!splitLine(line, ',', date, rateStr))
			continue;
		if (!isValidDate(date))
			continue;
		double rate;
		if (!parseValue(rateStr, rate))
			continue;
		_data[date] = static_cast<float>(rate);
	}
}

bool	BitcoinExchange::getRate(const std::string &date, float &rate) const{
	std::map<std::string, float>::const_iterator it = _data.upper_bound(date);
	if (it == _data.begin())
		return false;
	--it;
	rate = it->second;
	return true;
}

// ——— Processing —————————————————————————————————————————————————————————————————

std::string	BitcoinExchange::evaluateLine(const std::string &rawLine) const{
	std::string line = trim(rawLine);
	if (line.empty())
		return "";

	std::string date, valueStr;
	if (!splitLine(line, '|', date, valueStr))
		return "Error: bad input => " + line;
	if (date == "date")
		return "";
	if (!isValidDate(date))
		return "Error: bad input => " + line;
	double value;
	if (!parseValue(valueStr, value))
		return "Error: bad input => " + line;
	if (value < 0)
		return "Error: not a positive number.";
	if (value > 1000)
		return "Error: too large a number.";

	float rate;
	if (!getRate(date, rate))
		return "Error: bad input => " + line;
	float result = static_cast<float>(value) * rate;

	std::ostringstream oss;
	oss << date << " => " << value << " = " << result;
	return oss.str();
}
