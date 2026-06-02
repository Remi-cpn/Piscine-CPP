/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:09:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:14:24 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		//Constructors & destructor
		Ice(void);
		Ice(const Ice& srcIce);
		~Ice(void);
		
		//Member functions
		AMateria*		clone() const;
		void	use(ICharacter& target);
};

#endif