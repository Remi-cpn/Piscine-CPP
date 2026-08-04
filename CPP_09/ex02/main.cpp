/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:44:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/04 12:56:34 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

static void	printStackVec(std::vector<int> stack){
	for (std::vector<int>::iterator it = stack.begin(); it != stack.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

//static void	printStackLst(std::list<int> stack){
//	std::cout << "{";
//	for (std::list<int>::iterator it = stack.begin(); it != stack.end(); it++)
//		std::cout << " " << *it;
//	std::cout << " }" << std::endl;
//}

static bool	sameResult(const std::vector<int> &vec, const std::list<int> &lst){
	if (vec.size() != lst.size())
		return false;
	std::list<int>::const_iterator lit = lst.begin();
	for (std::vector<int>::const_iterator vit = vec.begin(); vit != vec.end(); vit++, lit++){
		if (*vit != *lit)
			return false;
	}
	return true;
}

static double	timeNowUs(void){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (double)tv.tv_sec * 1000000.0 + (double)tv.tv_usec;
}

int main (int ac, char **av){

	if (ac < 2 || !argValid(av[1])){
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pm;

	std::cout << "Before: " << av[1] << std::endl;

	double startVec = timeNowUs();
	pm.algoWithVector(av[1]);
	double timeVec = timeNowUs() - startVec;

	double startLst = timeNowUs();
	pm.algoWithLst(av[1]);
	double timeLst = timeNowUs() - startLst;

	std::cout << "After: ";
	printStackVec(pm.getVectorStack());

	if (!sameResult(pm.getVectorStack(), pm.getListStack())){
		std::cerr << "Warning: vector and list results differ!" << std::endl;
		return 1;
	}

	std::string plurial;
	if ((int)pm.getVectorStack().size() > 1)
		plurial = "s";
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << pm.getVectorStack().size() << " element" + plurial + " with std::vector : " << timeVec << " us";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << pm.getListStack().size() << " element" + plurial + " with std::list : " << timeLst << " us";
	std::cout << std::endl;
	return 0;
}