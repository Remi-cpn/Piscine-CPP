/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:00:29 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/16 08:12:36 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

RPN::RPN(): _stack(){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}
RPN::RPN(const RPN &src){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
	*this = src;
}
RPN& RPN::operator=(const RPN &src){
	if (this != &src){
		_stack = src._stack;
	}
	return *this;
}
RPN::~RPN(){
	std::cout << DIM << "Destructor called." << RESET << std::endl;
}





void	RPN::addNewDigit(int n){
	_stack.push(n);
}
int		RPN::takeLastDigit(){
	int	res = _stack.top();
	_stack.pop();
	return res;
}
int	RPN::doOperator(char ope){
	if (_stack.size() < 2)
		return -1;

	int nbr2 = takeLastDigit();
	int nbr1 = takeLastDigit();
	
	switch (ope){
		case '+': addNewDigit(nbr1 + nbr2); break;
		case '-': addNewDigit(nbr1 - nbr2); break;
		case '/': {
			if (nbr2 == 0){
				return -1;
			}
			addNewDigit(nbr1 / nbr2);
			break;
		}
		case '*': addNewDigit(nbr1 * nbr2); break;
		default: break;
	}

	return 0;
}
