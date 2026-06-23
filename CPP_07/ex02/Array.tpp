/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:06:48 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 12:38:55 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "iostream"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

template <typename T>
Array<T>::Array(): _n(0), _array(0){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): _n(n){
	std::cout << DIM << "Unsigned int constructor called." << RESET << std::endl;
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = 0;
}

template <typename T>
Array<T>::Array(const Array<T>& src): _n(0){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
	_array = new T();
	for (unsigned int i = 0; i < _n; i++)
		_array[i] = 0;
	*this = src;
}

template <typename T>
Array<T>::~Array(){
	std::cout << DIM << "Destructor called." << RESET << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& src){
	_n = src.size();
	delete[] _array;
	_array = new T[_n];
	for (unsigned int i = 0; i < src.size(); i++)
		_array[i] = src._array[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
	if (n >= _n)
		throw std::out_of_range("index out of bounds");
	return _array[n];
}

template <typename T>
unsigned int Array<T>::size()const{
	return _n;
}