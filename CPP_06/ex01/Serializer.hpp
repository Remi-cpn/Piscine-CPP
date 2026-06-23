/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:57:29 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 15:04:15 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

struct Data
{
	int test;
};

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer& src);
		Serializer& operator=(const Serializer& src);
		~Serializer();
};

#endif
