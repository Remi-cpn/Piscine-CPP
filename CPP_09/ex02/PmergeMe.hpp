/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:23 by rcompain          #+#    #+#             */
/*   Updated: 2026/07/21 22:58:01 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>

class PmergeMe
{
	private:
		 std::vector< std::pair<int, int>> _vectorStack;
		 std::list<int> _listStack;

	public:
		PmergeMe(char **);
		~PmergeMe();

		void algoWithVector(char**);
		void algoWithLst(char**);

		const std::vector< std::pair<int, int>> &getVectorStack() const;
};

bool argValid(char **);