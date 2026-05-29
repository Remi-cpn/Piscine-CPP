/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:30:49 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/28 12:49:16 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain&);
		~Brain();
		
		Brain& 		operator=(const Brain&);

		const std::string*	getIdeas(void) const;
		void				setIdeas(const std::string ideas[100]);
		std::string			getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);

	private:
		std::string _ideas[100];
};

#endif