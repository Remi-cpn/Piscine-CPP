/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:05:20 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/11 15:17:17 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();

		void addNumber(const int& n); 

	private:
		unsigned int _N;
};

#endif
