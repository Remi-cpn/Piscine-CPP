/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:22:27 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/09 14:39:13 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		//Constructors & destructor
		ScavTrap(void);
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& scavTrap);
		~ScavTrap(void);

		//Operator overload
		ScavTrap& 	operator=(const ScavTrap& srcScavTrap);
		
		//Member functions
		void 		guardGate();
		void		attack(const std::string& target);
};

#endif