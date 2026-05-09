/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:37:48 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/09 14:42:42 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
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
};

#endif