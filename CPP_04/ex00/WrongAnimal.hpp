/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:54:45 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 15:20:49 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		//Constructors & destructor
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& wrongAnimal);
		~WrongAnimal(void);

		//Operator overload
		WrongAnimal& operator=(const WrongAnimal& srcWrongAnimal);

		//Getters & Setters
		std::string getType(void) const;
		void		setType(std::string type);

		//Member functions
		void	makeSound(void) const;
	
	protected:
		std::string _type;
};

#endif