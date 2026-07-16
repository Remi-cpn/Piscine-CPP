/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 21:00:37 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/15 22:03:22 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN{
	
	private:
		std::stack <int> _stack;
	
	public:
		RPN();
		RPN(const RPN &);
		RPN& operator=(const RPN &);
		~RPN();
	
		void	addNewDigit(int);
		int		takeLastDigit();
		int		doOperator(char);
	
};