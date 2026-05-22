/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:11:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/18 14:32:05 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		//Constructors & destructor
		Cat(void);
		Cat(const Cat& cat);
		~Cat(void);

		//Operator overload
		Cat& 	operator=(const Cat& srcCat);

		//Member functions
		void	makeSound(void);
};

#endif