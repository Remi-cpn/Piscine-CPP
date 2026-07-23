/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:32 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/23 19:41:52 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

PmergeMe::PmergeMe(){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}
PmergeMe::~PmergeMe(){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
}


const std::vector<int> &PmergeMe::getVectorStack()const { return _vectorStack;}




bool	argValid(char *args){

	for (int i = 1; args[i]; i++){
		if (!isdigit(args[i]) && !isspace(args[i]))
			return false;
	}
	return true;
}




// ——— Algo With Vector ——————————————————————————————————————————————————————————


void	PmergeMe::algoWithVector(char *args){
	std::string str(args);
	initStackVec(str);
	printStackVec();
	recAlgoWithVector(1);
	printStackVec();

	
}

void	PmergeMe::recAlgoWithVector(int lvl){
	// Arret de la recursive
	if (lvl * 2 > (int)_vectorStack.size())
		return;

	std::cout << "Lvl = " << lvl << " ";
	printStackVec();
		
	//Boucle de swap
	for (size_t i = (lvl + lvl - 1); i < _vectorStack.size();)
	{
		if (_vectorStack[i] < _vectorStack[i - lvl]){
			for (int j = 0; j < lvl; j++)
				std::swap(_vectorStack[i - j], _vectorStack[i - lvl - j]);
		}
		i += lvl + lvl;
	}
	std::cout << "Lvl = " << lvl << " ";
	printStackVec();
	std::cout << std::endl;
	recAlgoWithVector(lvl * 2);
}

void	PmergeMe::initStackVec(std::string &args){
	
	long	nbr = 0;
	int		sign = 1;
	for (std::string::iterator it = args.begin(); it != args.end(); it++){
		if (*it == '-')
			sign *= -1;
		else if (*it != ' ')
			nbr = (nbr * 10) + *it - '0';
		if (it == args.end() || *(it + 1) == ' '){
			if (nbr >= std::numeric_limits<int>::min() || nbr <= std::numeric_limits<int>::max())
				_vectorStack.push_back(nbr * sign);
			nbr = 0;
			sign = 1;
		}
	}
}

void	PmergeMe::printStackVec(void){
	std::cout << "{";
	for (std::vector<int>::iterator it = _vectorStack.begin(); it != _vectorStack.end(); it++)
		std::cout << " " << *it;
	std::cout << " }" << std::endl;
}