/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:54:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 15:17:15 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
WrongAnimal::WrongAnimal(void): _type("Default_WrongAnimal"){
	std::cout << DIM << "WrongAnimal default constructor called" << RESET << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal){
	std::cout << DIM << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = wrongAnimal;
}
WrongAnimal::~WrongAnimal(void){
	std::cout << DIM << "WrongAnimal destructor called" << RESET << std::endl;
}



/* ——— Getters & Setters ———————————————————————————————————————————————————— */
std::string	WrongAnimal::getType(void) const { return _type;}
void		WrongAnimal::setType(std::string type) { _type = type;}


/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	WrongAnimal::makeSound(void) const { std::cout << "..." << std::endl; }



/* ——— Operator overload ———————————————————————————————————————————————————— */
WrongAnimal& 	WrongAnimal::operator=(const WrongAnimal& srcWrongAnimal){
	_type = srcWrongAnimal.getType();
	return *this;
}