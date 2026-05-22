/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:54:45 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/18 14:31:49 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		//Constructors & destructor
		Animal(void);
		Animal(const Animal& animal);
		~Animal(void);

		//Operator overload
		Animal& operator=(const Animal& srcAnimal);

		//Getters & Setters
		std::string getType(void) const;
		void		setType(std::string type);

		//Member functions
		void	makeSound(void);
	
	protected:
		std::string _type;
};

#endif