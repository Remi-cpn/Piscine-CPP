/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:57:12 by rcompain          #+#    #+#             */
/*   Updated: 2026/04/24 15:25:03 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

#define YELLOW  "\033[33m"
#define DIM		"\033[2m"
#define RESET   "\033[0m"

class Zombie
{
	public:

		Zombie(void);
		~Zombie(void);

		void setName(std::string name);
		
		void announce(void);

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif