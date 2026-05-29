/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:54:45 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/29 09:54:32 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		//Constructors & destructor
		AAnimal(void);
		AAnimal(const AAnimal& animal);
		virtual ~AAnimal(void);

		//Operator overload
		AAnimal& operator=(const AAnimal& srcAnimal);

		//Getters & Setters
		std::string getType(void) const;
		void		setType(std::string type);

		//Member functions
		virtual void	makeSound(void) const = 0;
	
	protected:
		std::string _type;
};

#endif