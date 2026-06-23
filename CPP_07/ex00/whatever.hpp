/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:25:48 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 17:46:10 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T& a, T& b){
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T max(T a, T b){
	return (a > b) ? a : b; 
}

template <typename T>
T min(T a, T b){
	return (a < b) ? a : b; 
}