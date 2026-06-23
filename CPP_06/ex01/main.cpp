/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:57:19 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 15:07:29 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main (){
	Data d;
	uintptr_t ptr;
	Data* d_ptr;

	d.test = 42;

	ptr = Serializer::serialize(&d);
	d_ptr = Serializer::deserialize(ptr);

	std::cout << "Original pointer:  " << &d << std::endl;
	std::cout << "Serialized value:  " << ptr << std::endl;
	std::cout << "Deserialized ptr:  " << d_ptr << std::endl;

	if (d_ptr == &d)
		std::cout << "Pointers match! d_ptr->test = " << d_ptr->test << std::endl;
	else
		std::cout << "Pointers do not match!" << std::endl;

	return 0;
}