/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:26:18 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/08 14:15:59 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		//Constructors & destructor
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& clapTrap);
		~ClapTrap(void);

		//Operator overload
		ClapTrap& 	operator=(const ClapTrap& srcClapTrap);

		//Member functions
		void		attack(const std::string& target);
		void 		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		
		//Getters & Setters
		std::string	getName(void) const;
		int			getHP(void) const;
		int			getEP(void) const;
		int			getAD(void) const;
		
	private:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif