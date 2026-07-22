/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:32 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/21 22:58:23 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

PmergeMe::PmergeMe(char **src){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
	for (int i = 0; src[i]; i++){
		_vectorStack.push_back(atoi(src[i]));
		_listStack.push_back(atoi(src[i]));
	}
}
PmergeMe::~PmergeMe(){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
}


const std::vector<std::pair<int, int>> &PmergeMe::getVectorStack()const { return _vectorStack;}




bool argValid(char **args){
	
}