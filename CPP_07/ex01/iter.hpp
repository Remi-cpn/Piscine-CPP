/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:30:09 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 10:56:43 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

template <typename T, typename F>
void iter(T* array, const size_t size, F f){
	for (size_t it = 0; it < size; it++){
		f(array[it]);
	}
};