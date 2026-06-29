/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:05:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/29 12:36:53 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

Span::Span(): _N(0), _data(0){
	std::cout << DIM << "Span default constructor called" << RESET << std::endl;
}

Span::Span(unsigned int N): _N(N), _data(0){
	std::cout << DIM << "Span unsigned int constructor called" << RESET << std::endl;
}

Span::Span(const Span& src){
	std::cout << DIM << "Span copy constructor called" << RESET << std::endl;
	*this = src;
}

Span& Span::operator=(const Span& src){
	std::cout << DIM << "Span assignment operator called" << RESET << std::endl;
	_N = src._N;
	_data = src._data;
	return *this;
}

Span::~Span(){
	std::cout << DIM << "Span destructor called" << RESET << std::endl;
}


void Span::addNumber(const int& n){
	if (_data.size() >= _N)
		throw std::runtime_error("container full.");
	_data.push_back(n);
}

int Span::shortestSpan()const{
	std::vector<int> tmp = this->_data;
	if (_data.size() < 2)
		throw std::runtime_error("need more integer.");
	std::sort(tmp.begin(), tmp.end());
	int res = 0;
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++){
		if (it == tmp.begin()){
			continue;
		}
		int new_res = *it - (*(it - 1));
		if (new_res < res || it == tmp.begin() + 1)
			res = new_res;
	}
	return res;
}
int Span::longestSpan()const{
	std::vector<int> tmp = this->_data;
	if (_data.size() < 2)
		throw std::runtime_error("need more integer.");
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end() - 1) - *(tmp.begin());
}
