/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:30:38 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 16:43:32 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <algorithm>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

/* ——— Constructor & Destructor ————————————————————————————————————————————— */
Brain::Brain(void){
	std::cout << DIM << "Brain default constructor called" << RESET << std::endl;
}
Brain::Brain(const Brain& Brain){
	std::cout << DIM << "Brain copy constructor called" << RESET << std::endl;
}
Brain::~Brain(void){
	std::cout << DIM << "Brain destructor called" << RESET << std::endl;
}

/* ——— Methodes ————————————————————————————————————————————————————————————— */


/* ——— Getters & Setters ———————————————————————————————————————————————————— */
void 			Brain::setIdeas(const std::string ideas[100]) { std::copy(ideas, ideas + 100, _ideas); }
std::string* 	Brain::getIdeas(void) const { return _ideas;}

/* ——— Operator overload ———————————————————————————————————————————————————— */
Brain& 	Brain::operator=(const Brain& srcBrain){
	std::copy(srcBrain.getIdeas(), srcBrain.getIdeas() + 100, _ideas);
	return *this;
}