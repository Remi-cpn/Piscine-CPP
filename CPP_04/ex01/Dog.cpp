/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:10:50 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/28 13:00:10 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Dog::Dog(void): Animal(){
	std::cout << DIM << "Dog default constructor called" << RESET << std::endl;
	_type = "Dog";
	_brain = new Brain();
}
Dog::Dog(const Dog& dog) : Animal(dog){
	std::cout << DIM << "Dog copy constructor called" << RESET << std::endl;
	_brain = new Brain(*dog._brain);
}
Dog::~Dog(void){
	std::cout << DIM << "Dog destructor called" << RESET << std::endl;
	delete _brain;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	Dog::makeSound(void) const { std::cout << "Whouaff" << std::endl; }
Brain*	Dog::getBrain(void) const { return _brain; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
Dog& 	Dog::operator=(const Dog& srcDog){
	if (this != &srcDog)
	{
		Animal::operator=(srcDog);
		*_brain = *srcDog._brain;
	}
	return *this;
}