/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:57:34 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 15:10:24 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

Serializer::Serializer()
{
	std::cout << DIM << "Serializer default constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer& src)
{
	(void)src;
	std::cout << DIM << "Serializer copy constructor called" << RESET << std::endl;
}

Serializer& Serializer::operator=(const Serializer& src)
{
	(void)src;
	std::cout << DIM << "Serializer assignment operator called" << RESET << std::endl;
	return *this;
}

Serializer::~Serializer()
{
	std::cout << DIM << "Serializer destructor called" << RESET << std::endl;
}


uintptr_t	Serializer::serialize(Data* ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*		Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}