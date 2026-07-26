/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:32 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/26 18:28:13 by rcompain         ###   ########.fr       */
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



// ——— Algo With Lst ——————————————————————————————————————————————————————————

void	PmergeMe::algoWithLst(char *args){
	std::string str(args);
	initStackLst(str);
	printStackLst();
	recAlgoWithLst(1);
	printStackLst();

	
}

void	PmergeMe::recAlgoWithLst(int lvl){
	// Arret de la recursive
	if (lvl * 2 > (int)_listStack.size())
		return;

	std::cout << "Lvl = " << lvl << " ";
	printStackLst();
		
	//Boucle de swap
	std::list<int>::iterator it = _listStack.begin();
	int size = _listStack.size();
	int count = lvl + lvl;
	for (std::advance(it, lvl + lvl - 1);;)
	{
		std::list<int>::iterator itk = it;
		std::advance(itk, -lvl);
		if (*it < *itk){
			for (int j = 0; j < lvl; j++){
				std::list<int>::iterator iti = it;
				std::list<int>::iterator itj = it;
				std::advance(iti, -j);
				std::advance(itj, -(lvl + j));
				int value;
				value = *iti;
				*iti = *itj;
				*itj = value;
			}
		}
		int i = 0;
		for(; i < lvl + lvl; i++){
			std::advance(it, 1);
			count++;
		}
		if (count > size)
			break;
	}
	std::cout << "Lvl = " << lvl << " ";
	printStackLst();
	std::cout << std::endl;
	recAlgoWithLst(lvl * 2);
}

// std::list &operator[]

void	PmergeMe::initStackLst(std::string &args){
	
	long	nbr = 0;
	int		sign = 1;
	for (std::string::iterator it = args.begin(); it != args.end(); it++){
		if (*it == '-')
			sign *= -1;
		else if (*it != ' ')
			nbr = (nbr * 10) + *it - '0';
		if (it == args.end() || *(it + 1) == ' '){
			if (nbr >= std::numeric_limits<int>::min() || nbr <= std::numeric_limits<int>::max())
				_listStack.push_back(nbr * sign);
			nbr = 0;
			sign = 1;
		}
	}
}

void	PmergeMe::printStackLst(void){
	std::cout << "{";
	for (std::list<int>::iterator it = _listStack.begin(); it != _listStack.end(); it++)
		std::cout << " " << *it;
	std::cout << " }" << std::endl;
}
