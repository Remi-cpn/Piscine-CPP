/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:10:50 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/18 14:24:45 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Dog::Dog(void): Animal(){
	std::cout << DIM << "Dog default constructor called" << RESET << std::endl;
	Animal::_type = "Dog";
}
Dog::Dog(const Dog& Dog){
	std::cout << DIM << "Dog copy constructor called" << RESET << std::endl;
	*this = Dog;
}
Dog::~Dog(void){
	std::cout << DIM << "Dog destructor called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	Dog::makeSound(void) { std::cout << "Whouaff" << std::endl; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
Dog& 	Dog::operator=(const Dog& srcDog){
	Animal::operator=(srcDog);
	return *this;
}