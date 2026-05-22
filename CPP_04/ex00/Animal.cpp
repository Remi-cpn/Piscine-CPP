/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:54:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/18 14:32:50 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Animal::Animal(void): _type("Default_Animal"){
	std::cout << DIM << "Animal default constructor called" << RESET << std::endl;
}
Animal::Animal(const Animal& animal){
	std::cout << DIM << "Animal copy constructor called" << RESET << std::endl;
	*this = animal;
}
Animal::~Animal(void){
	std::cout << DIM << "Animal destructor called" << RESET << std::endl;
}



/* ——— Getters & Setters ———————————————————————————————————————————————————— */
std::string	Animal::getType(void) const { return _type;}
void		Animal::setType(std::string type) { _type = type;}


/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	Animal::makeSound(void) { std::cout << "..." << std::endl; }



/* ——— Operator overload ———————————————————————————————————————————————————— */
Animal& 	Animal::operator=(const Animal& srcAnimal){
	_type = srcAnimal.getType();
	return *this;
}