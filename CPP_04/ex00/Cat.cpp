/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:10:50 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/18 14:27:46 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Cat::Cat(void): Animal(){
	std::cout << DIM << "Cat default constructor called" << RESET << std::endl;
	Animal::_type = "Cat";
}
Cat::Cat(const Cat& cat){
	std::cout << DIM << "Cat copy constructor called" << RESET << std::endl;
	*this = cat;
}
Cat::~Cat(void){
	std::cout << DIM << "Cat destructor called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	Cat::makeSound(void) { std::cout << "Miaouw" << std::endl; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
Cat& 	Cat::operator=(const Cat& srcCat){
	Animal::operator=(srcCat);
	return *this;
}