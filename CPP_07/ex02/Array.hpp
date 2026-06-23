/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 11:02:04 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 12:37:09 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& array);
		~Array();

		Array<T>& operator=(const Array<T>& src);
		T& operator[](unsigned int n);

		unsigned int size()const;

	private:
		unsigned int _n;
		T* _array;
};

#include "Array.tpp"