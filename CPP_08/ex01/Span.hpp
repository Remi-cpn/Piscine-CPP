/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:05:20 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/29 12:38:48 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span
{
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();

		void addNumber(const int& n);
		
		template <typename Iterator>
		void addNumber(Iterator first, Iterator last){
			for (Iterator it = first; it != last; it++){
				if (_data.size() >= _N)
				throw std::runtime_error("container full.");
			_data.push_back(*it);
			}
		}
		
		int shortestSpan()const;
		int longestSpan()const;

	private:
		unsigned int _N;
		std::vector<int> _data;
};

#endif
