/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:22:27 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/12 15:27:57 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : public virtual ClapTrap
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

	protected:
		static const int _hitPointsBegin = 100;
		static const int _energyPointsBegin = 50;
		static const int _attackDamageBegin = 20;
};

#endif