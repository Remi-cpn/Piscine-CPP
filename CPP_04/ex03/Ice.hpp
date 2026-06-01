/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 16:09:54 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/01 18:16:48 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria, public Character
{
	public:
		//Constructors & destructor
		Ice(void);
		Ice(const Ice& srcIce);
		~Ice(void);

		//Operator overload
		
		//Getters & Setters
		std::string const & getName() const;
		
		//Member functions
		AMateria*		clone() const;
		void	use(ICharacter& target);
};

#endif