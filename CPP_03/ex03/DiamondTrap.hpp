/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:34:10 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/12 15:49:25 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		//Constructors & destructor
		DiamondTrap(void);
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& diamondTrap);
		~DiamondTrap(void);

		//Operator overload
		DiamondTrap& 	operator=(const DiamondTrap& srcDiamondTrap);
		
		//Getters & Setters
		std::string		getNameDiamond(void) const;
		void			setNameDiamond(const std::string &name);

		//Member functions
		void			whoAmI(void);
		void			attack(const std::string& target);

	private:
		std::string		_name;
};

#endif