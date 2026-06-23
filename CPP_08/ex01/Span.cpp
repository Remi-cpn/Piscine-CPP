/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:05:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 15:17:23 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

Span::Span(): _N(0){
	std::cout << DIM << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N): _N(N){
	std::cout << DIM << "Span unsigned int constructor called" << RESET << std::endl;
}

Span::Span(const Span& src){
	std::cout << DIM << "Span copy constructor called" << RESET << std::endl;
	*this = src;
}

Span& Span::operator=(const Span& src){
	std::cout << DIM << "Span assignment operator called" << RESET << std::endl;
	_N = src._N;
	return *this;
}

Span::~Span(){
	std::cout << DIM << "Span destructor called" << RESET << std::endl;
}


void Span::addNumber(const int& n){
	
}