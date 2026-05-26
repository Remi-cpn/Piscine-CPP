/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:20:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 15:20:00 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
WrongCat::WrongCat(void) : WrongAnimal(){
	std::cout << DIM << "WrongCat default constructor called" << RESET << std::endl;
	_type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat){
	std::cout << DIM << "WrongCat copy constructor called" << RESET << std::endl;
}
WrongCat::~WrongCat(void){
	std::cout << DIM << "WrongCat destructor called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */
void	WrongCat::makeSound(void) const { std::cout << "WrongMiaouw" << std::endl; }


/* ——— Operator overload ———————————————————————————————————————————————————— */
WrongCat& 	WrongCat::operator=(const WrongCat& srcWrongCat){
	WrongAnimal::operator=(srcWrongCat);
	return *this;
}
