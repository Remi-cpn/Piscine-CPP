/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:43:20 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/29 13:58:01 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "iostream"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

template <typename T>
MutantStack<T>::MutantStack():_data(0){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
	_data = src._data;
	*this = src;
}

template <typename T>
MutantStack<T>::~MutantStack(){
	std::cout << DIM << "Destructor called." << RESET << std::endl;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& src){
	_data = src._data;
	return *this;
}

template <typename T>
iterator MutantStack<T>::begin(){
	return _data.begin();
}

template <typename T>
iterator MutantStack<T>::end(){
	return _data.end();
}