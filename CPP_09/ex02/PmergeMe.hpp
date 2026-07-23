/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/23 19:07:39 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
	// ——— Algo With Vector ————————————————————————————————————————————————————
		std::vector<int> _vectorStack;
		
		void	initStackVec(std::string &);


	// ——— Algo With Lst ———————————————————————————————————————————————————————
		std::list<int> _listStack;
		
		void	initStackLst(std::string &);

	public:
		PmergeMe();
		~PmergeMe();
	
	// ——— Algo With Vector ————————————————————————————————————————————————————
		void	algoWithVector(char*);
		void	recAlgoWithVector(int);
		void	printStackVec(void);


	// ——— Algo With Lst ———————————————————————————————————————————————————————
		void	algoWithLst(char*);

		const std::vector<int>	&getVectorStack() const;
};

bool	argValid(char *);