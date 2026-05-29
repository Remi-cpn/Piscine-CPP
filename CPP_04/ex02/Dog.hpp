/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:11:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/29 09:55:33 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		//Constructors & destructor
		Dog(void);
		Dog(const Dog& dog);
		~Dog(void);

		//Operator overload
		Dog& 	operator=(const Dog& srcDog);

		//Member functions
		void	makeSound(void) const;
		Brain*	getBrain(void) const;

	private:
		Brain* _brain;
};

#endif