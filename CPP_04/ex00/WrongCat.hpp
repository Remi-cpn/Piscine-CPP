/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:11:00 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 15:20:21 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		//Constructors & destructor
		WrongCat(void);
		WrongCat(const WrongCat& WrongCat);
		~WrongCat(void);

		//Operator overload
		WrongCat& 	operator=(const WrongCat& srcWrongCat);

		//Member functions
		void	makeSound(void) const;
};

#endif