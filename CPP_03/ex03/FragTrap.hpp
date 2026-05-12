/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:37:48 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/12 15:26:15 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public virtual ClapTrap
{
	public:
		//Constructors & destructor
		FragTrap(void);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& fragTrap);
		~FragTrap(void);

		//Operator overload
		FragTrap& 	operator=(const FragTrap& srcFragTrap);
		
		//Member functions
		void		highFivesGuys(void);

	protected:
		static const int _hitPointsBegin = 100;
		static const int _energyPointsBegin = 100;
		static const int _attackDamageBegin = 30;
};

#endif