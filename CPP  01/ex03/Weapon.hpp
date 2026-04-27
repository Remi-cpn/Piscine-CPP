/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:24:52 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/27 11:59:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

class Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		std::string const& getType(void);
		void setType(std::string type);

	private:
		std::string _type;
};

#endif