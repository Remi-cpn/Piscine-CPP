/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/27 12:41:31 by rcompain         ###   ########.fr       */
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
		void	printStackVec(void);
		std::vector<int>::iterator lowerBoundVec(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& value);



	// ——— Algo With Lst ———————————————————————————————————————————————————————
		std::list<int> _listStack;
		
		void	initStackLst(std::string &);
		void	recAlgoWithLst(int);
		void	printStackLst(void);

	public:
		PmergeMe();
		~PmergeMe();
	
	// ——— Algo With Vector ————————————————————————————————————————————————————
		void	algoWithVector(char*);

	// ——— Algo With Lst ———————————————————————————————————————————————————————
		void	algoWithLst(char*);

		const std::vector<int>	&getVectorStack() const;
		const std::list<int>	&getLstStack() const;
};

bool	argValid(char *);