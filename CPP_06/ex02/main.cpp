/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:15:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 16:51:17 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
	std::srand(std::time(NULL));

	for (int i = 0; i < 6; i++)
	{
		Base* p = generate();

		identify(p);
		identify(*p);

		delete p;
	}

	return 0;
}