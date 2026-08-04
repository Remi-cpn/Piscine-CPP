/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/04 12:34:53 by rcompain         ###   ########.fr       */
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
		void	recAlgoWithVector(int);

	// ——— Algo With Lst ———————————————————————————————————————————————————————
		std::list<int> _listStack;
		
		void	initStackLst(std::string &);
		void	recAlgoWithLst(int);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe	&operator=(const PmergeMe &src);
		~PmergeMe();
	
	// ——— Algo With Vector ————————————————————————————————————————————————————
		void	algoWithVector(char*);

	// ——— Algo With Lst ———————————————————————————————————————————————————————
		void	algoWithLst(char*);

		const std::vector<int> &getVectorStack()const;
		const std::list<int> &getListStack()const;
};

bool	argValid(char *);