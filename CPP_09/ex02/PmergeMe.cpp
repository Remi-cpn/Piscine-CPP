/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:32 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/18 16:01:58 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

PmergeMe::PmergeMe(int *src){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}
PmergeMe::~PmergeMe(){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
}





bool argValid(char **args){
	
}