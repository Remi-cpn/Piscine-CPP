/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/08 11:03:16 by rcompain         ###   ########.fr       */
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
		void	algoWithVector(std::string &);

	// ——— Algo With Lst ———————————————————————————————————————————————————————
		void	algoWithLst(std::string &);

		const std::vector<int> &getVectorStack()const;
		const std::list<int> &getListStack()const;
};

bool	argValid(std::string &);