/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:26:18 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/29 09:33:13 by rcompain         ###   ########.fr       */
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
		virtual ~ClapTrap(void);

		//Operator overload
		ClapTrap& 		operator=(const ClapTrap& srcClapTrap);

		//Member functions
		virtual void	attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		
		//Getters & Setters
		std::string		getName(void) const;
		int				getHP(void) const;
		int				getEP(void) const;
		int				getAD(void) const;
		void			setName(const std::string &name);
		void			setHP(int hitPoints);
		void			setEP(int energyPoints);
		void			setAD(int attackDamage);
		
	protected:
		std::string 	_name;
		int				_hitPoints;
		int				_energyPoints;
		int				_attackDamage;
};

#endif