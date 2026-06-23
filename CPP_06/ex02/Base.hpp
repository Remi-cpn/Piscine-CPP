/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 16:16:14 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/10 17:12:04 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base{};
class C : public Base{};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif

