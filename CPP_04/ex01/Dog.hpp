/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:11:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/28 12:58:32 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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