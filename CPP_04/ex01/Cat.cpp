/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:10:50 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 15:05:48 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Cat::Cat(void): Animal(){
	std::cout << DIM << "Cat default constructor called" << RESET << std::endl;
	_type = "Cat";
}
Cat::Cat(const Cat& cat) : Animal(cat){
	std::cout << DIM << "Cat copy constructor called" << RESET << std::endl;
}
Cat::~Cat(void){
	std::cout << DIM << "Cat destructor called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	Cat::makeSound(void) const { std::cout << "Miaouw" << std::endl; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
Cat& 	Cat::operator=(const Cat& srcCat){
	Animal::operator=(srcCat);
	return *this;
}