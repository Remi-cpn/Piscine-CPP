/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:05:05 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/17 09:43:43 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Phonebook::Phonebook(void)
{
	std::cout << "Constructor called" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Destructor called" << std::endl;
}



/* ——— Private Variables ———————————————————————————————————————————————————— */
int Phonebook::_nbContact = 0;

int	Phonebook::getNbContact(void) { return _nbContact; }



/* ——— Function add ————————————————————————————————————————————————————————— */
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

	// Check if EOF is reached
	if (std::cin.eof())
		return "";
	
	std::cout << prompt;
	std::getline(std::cin, input);

	// Check if input is empty, if phone number is only digit and if index is valid
	if (input.empty())
	{
		std::cout << "Need something !" << std::endl;
		input = getInput(prompt);
	}
	if (prompt == "Phone number: " && isDigit(input) == false)
	{
		std::cout << "Need only digit !" << std::endl;
		input = getInput(prompt);
	}
	if (prompt == "Index: " && (input.length() != 1 || !std::isdigit(input[0]) || std::atoi(input.c_str()) < 0 || std::atoi(input.c_str()) >= Phonebook::getNbContact()))
	{
		std::cout << "Invalid index" << std::endl;
		input = getInput(prompt);
	}
	return input;
}

void	Phonebook::add(void)
{
	static int	i = 0;

	if (i == 8)
		i = 0;
	if (Phonebook::_nbContact < 8)
		Phonebook::_nbContact++;

	// Get contact info
	this->_list[i].setFirstName(getInput("First name: "));
	this->_list[i].setLastName(getInput("Last name: "));
	this->_list[i].setNickName(getInput("Nickname: "));
	this->_list[i].setPhoneNumber(getInput("Phone number: "));
	this->_list[i].setDarkestSecret(getInput("Darkest secret: "));
	std::cout << "New contact added" << std::endl;
	
	i++;
}



/* ——— Function search —————————————————————————————————————————————————————— */
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
	// Display contact list
	std::cout << " | " << std::setw(10) << std::right << "Index" << " | ";
	std::cout << std::setw(10) << std::right << "First Name" << " | ";
	std::cout << std::setw(10) << std::right << "Last Name" << " | ";
	std::cout << std::setw(10) << std::right << "Nick Name" << " | " << std::endl;
	for (int i = 0; i < 8 && !this->_list[i].getFirstName().empty(); i++)
	{
		std::cout << " | " << std::setw(10) << std::right << i << " | ";
		std::cout << std::setw(10) << std::right << formateString(this->_list[i].getFirstName(), 10) << " | ";
		std::cout << std::setw(10) << std::right << formateString(this->_list[i].getLastName(), 10) << " | ";
		std::cout << std::setw(10) << std::right << formateString(this->_list[i].getNickName(), 10) << " | " << std::endl;
	}

	// Get index and display contact info
	if (_nbContact == 0)
	{
		std::cout << "No contacts." << std::endl;
		return ;
	}
	std::string input = getInput("Index: ");
	if (input.empty())
		return ;
	int index = std::atoi(input.c_str());
	std::cout << "First name: " << this->_list[index].getFirstName() << std::endl;
	std::cout << "Last name: " << this->_list[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_list[index].getNickName() << std::endl;
	std::cout << "Phone number: " << this->_list[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << this->_list[index].getDarkestSecret() << std::endl;
}
