/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:14:33 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/05 11:52:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;

		BitcoinExchange();

		void	loadDatabase(const std::string &filename);
		bool	getRate(const std::string &date, float &rate) const;

	public:
		BitcoinExchange(const std::string &filename);
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange	&operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		std::string	evaluateLine(const std::string &rawLine) const;
};
