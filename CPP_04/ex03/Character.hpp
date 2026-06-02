/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:09:58 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 11:49:37 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		//Constructors & destructor
		Character(void);
		Character(const Character& srcCharacter);
		Character(std::string const& name );
		~Character(void);

		//Operator overload
		Character& operator=(const Character& srcCharcater);

		//Getters & Setters
		std::string const & getName() const;
		
		//Member functions
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);


	private:
		std::string _name;
		AMateria* _inventory[4];
		AMateria* _floor[100];
};

#endif