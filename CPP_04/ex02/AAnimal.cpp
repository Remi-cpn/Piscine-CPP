/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:54:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/29 09:56:53 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
AAnimal::AAnimal(void): _type("Default_AAnimal"){
	std::cout << DIM << "AAnimal default constructor called" << RESET << std::endl;
}
AAnimal::AAnimal(const AAnimal& animal){
	std::cout << DIM << "AAnimal copy constructor called" << RESET << std::endl;
	*this = animal;
}
AAnimal::~AAnimal(void){
	std::cout << DIM << "AAnimal destructor called" << RESET << std::endl;
}


/* ——— Getters & Setters ———————————————————————————————————————————————————— */
std::string	AAnimal::getType(void) const { return _type;}
void		AAnimal::setType(std::string type) { _type = type;}


/* ——— Operator overload ———————————————————————————————————————————————————— */
AAnimal& 	AAnimal::operator=(const AAnimal& srcAAnimal){
	_type = srcAAnimal.getType();
	return *this;
}