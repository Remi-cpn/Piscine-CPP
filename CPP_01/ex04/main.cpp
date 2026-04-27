/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:55:22 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 15:16:40 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void ft_sed(std::string& str, std::string& s1, std::string& s2)
{
	std::string result;
	size_t		pos = 0;
	
	if (s1.empty())
		return ;
	
	for (size_t found = 0; (found = str.find(s1, pos)) != std::string::npos; pos = found + s1.length())
		result += str.substr(pos, found - pos) + s2;
	result += str.substr(pos);
	str = result;
}

int main (int ac, char **av)
{
	if (ac != 4)
		return 1;
		
	std::ifstream inFile(av[1]);
	if (!inFile)
	{
		std::cerr << "Unable to open the file!" << std::endl;
		return 1;
	}

	std::string outFileName = std::string(av[1]) + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!outFile)
	{
		std::cerr << "Unable to open the file!" << std::endl;
		return 1;
	}
	
	std::string str;
	std::string s1 = av[2];
	std::string s2 = av[3];
	while (std::getline(inFile, str))
	{
		ft_sed(str, s1, s2);
		outFile << str;
		if (!inFile.eof())
			outFile << std::endl;
	}
	return 0;
}
