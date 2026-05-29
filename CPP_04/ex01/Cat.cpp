/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:10:50 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/28 12:58:11 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Cat::Cat(void): Animal(){
	std::cout << DIM << "Cat default constructor called" << RESET << std::endl;
	_type = "Cat";
	_brain = new Brain();
}
Cat::Cat(const Cat& cat) : Animal(cat){
	std::cout << DIM << "Cat copy constructor called" << RESET << std::endl;
	_brain = new Brain(*cat._brain);
}
Cat::~Cat(void){
	std::cout << DIM << "Cat destructor called" << RESET << std::endl;
	delete _brain;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	Cat::makeSound(void) const { std::cout << "Miaouw" << std::endl; }
Brain*	Cat::getBrain(void) const { return _brain; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
Cat& 	Cat::operator=(const Cat& srcCat){
	if (this != &srcCat)
	{
		Animal::operator=(srcCat);
		*_brain = *srcCat._brain;
	}
	return *this;
}