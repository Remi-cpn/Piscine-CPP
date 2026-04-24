/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:28 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 16:56:22 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

class HumanA
{
	public:
		std::string name;
		Weapon weapon;
	
		HumanA(void);
		HumanA(std::string name, Weapon weapon);
		~HumanA(void);

		void attack(void);
};

#endif