/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:25:40 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 17:01:04 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

#define DIM		"\033[2m"
#define RESET   "\033[0m"

class HumanB
{
	public:
		std::string name;
		Weapon weapon;
	
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);

		void setWeapon(Weapon weapon);

		void attack(void);
};

#endif