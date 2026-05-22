/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:57:12 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/19 14:53:09 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
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
		Zombie(std::string name);
		~Zombie(void);

		void announce(void);

	private:
		std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif