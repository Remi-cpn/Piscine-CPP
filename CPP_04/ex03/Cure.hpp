/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:03:33 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:14:22 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		//Constructors & destructor
		Cure(void);
		Cure(const Cure& srcCure);
		~Cure(void);
		
		//Member functions
		AMateria*		clone() const;
		void	use(ICharacter& target);
};

#endif