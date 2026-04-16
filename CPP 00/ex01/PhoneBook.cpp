/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:05:05 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/16 15:52:49 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

/** ——— Class Phonebook —————————————————————————————————————————————————————— */
// ——— Constructor ———— 
Phonebook::Phonebook(void)
{
	std::cout << "Constructor called" << std::endl;
}

// ——— Destructor ———— 
Phonebook::~Phonebook(void)
{
	std::cout << "Destructor called" << std::endl;
}

// ——— Function add ———— 
static bool isDigit(std::string prompt)
{
	for (std::string::iterator it = prompt.begin(); it != prompt.end(); it++)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

static std::string getInput(std::string prompt)
{
	std::string input;

	if (std::cin.eof())
		return "";
	std::cout << prompt;
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Need somethink !" << std::endl;
		input = getInput(prompt);
	}
	if (prompt == "Phone number: " && isDigit(input) == false)
	{
		std::cout << "Need only digit !" << std::endl;
		input = getInput(prompt);
	}
	return input;
}

void	Phonebook::add(void)
{
	static int	i = 0;

	if (i == 8)
		i = 0;
	this->list[i].firstName = getInput("First name: ");
	this->list[i].lastName = getInput("Last name: ");
	this->list[i].nickName = getInput("Nickname: ");
	this->list[i].phoneNumber = getInput("Phone number: ");
	this->list[i].darkestSecret = getInput("Darkest secret: ");
	std::cout << "New contact added" << std::endl;
}

// ——— Function search ————
static std::string formateString(std::string str, int max)
{
	std::string newString;

	if ((int)str.length() > max)
	{
		newString = str.substr(0, max - 1) + ".";
		return newString;
	}
	return str;
}
void	Phonebook::search(void)
{
	std::cout << " | " << std::setw(10) << std::right << "Index" << " | ";
	std::cout << std::setw(10) << std::right << "First Name" << " | ";
	std::cout << std::setw(10) << std::right << "Last Name" << " | ";
	std::cout << std::setw(10) << std::right << "Nick Name" << " | " << std::endl;
	for (int i = 0; i < 8 && !this->list[i].firstName.empty(); i++)
	{
		std::cout << " | " << std::setw(10) << std::right << i << " | ";
		std::cout << std::setw(10) << std::right << formateString(this->list[i].firstName, 10) << " | ";
		std::cout << std::setw(10) << std::right << formateString(this->list[i].lastName, 10) << " | ";
		std::cout << std::setw(10) << std::right << formateString(this->list[i].nickName, 10) << " | " << std::endl;
	}
}
