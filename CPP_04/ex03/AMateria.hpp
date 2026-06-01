/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 13:18:25 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/01 16:06:15 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	public:
		//Constructors & destructor
		AMateria(void);
		AMateria(const AMateria& srcAMateria);
		AMateria(std::string const & type);
		virtual ~AMateria(void);
	
		//Operator overload
		AMateria& 			operator=(const AMateria& srcAMateria);

		//Getters & Setters
		std::string const & getType() const;
		void				setType(const std::string type);

		//Member functions
		virtual AMateria*	clone() const = 0;
		virtual void 		use(ICharacter& target);

	protected:
		std::string _type;
	
};

#endif