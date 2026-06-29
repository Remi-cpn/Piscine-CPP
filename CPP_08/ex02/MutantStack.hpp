/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 12:43:12 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/29 13:56:59 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>{
	public:
		MutantStack();
		MutantStack(const MutantStack<T>& mutantStack);
		MutantStack<T>& operator=(const MutantStack<T>& src);
		~MutantStack();

		typedef typename std::stack<T>::iterator iterator;

		iterator begin();
		iterator end();
	
	private:
		std::stack<T> _data;
		
};

#include "MutantStack.tpp"