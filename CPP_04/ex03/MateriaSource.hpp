/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 18:04:30 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:36:29 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"


class MateriaSource: public IMateriaSource
{
	public:
		//Constructors & destructor
		MateriaSource(void);
		MateriaSource(const MateriaSource& srcMateriaSource);
		~MateriaSource(void);

		//Operator overload
		MateriaSource& operator=(const MateriaSource& srcMateriaSource);

		//Member functions
		void learnMateria(AMateria* newMateria);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria* _spells[4];
};

#endif