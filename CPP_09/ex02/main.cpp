/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:44:11 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/08 11:11:21 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

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

static std::string	concatArgs(int ac, char **av){
	std::string args;
	for (int i = 1; i < ac; i++){
		if (i > 1)
			args += " ";
		args += av[i];
	}
	return args;
}

int main (int ac, char **av){

	std::string args = concatArgs(ac, av);

	if (ac < 2 || !argValid(args)){
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe pm;

	std::cout << "Before: " << args << std::endl;

	double timeVec = timeNowUs();
	pm.algoWithVector(args);
	timeVec = timeNowUs() - timeVec;

	double timeLst = timeNowUs();
	pm.algoWithLst(args);
	timeLst = timeNowUs() - timeLst;

	std::cout << "After: ";
	printStackVec(pm.getVectorStack());

	if (!sameResult(pm.getVectorStack(), pm.getListStack())){
		std::cerr << "Warning: vector and list results differ!" << std::endl;
		return 1;
	}

	std::string plurial;
	if ((int)pm.getVectorStack().size() > 1)
		plurial = "s";
	std::cout << "Time to process a range of " << pm.getVectorStack().size() << " element" + plurial + " with std::vector : " << timeVec << " us";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << pm.getListStack().size() << " element" + plurial + " with std::list : " << timeLst << " us";
	std::cout << std::endl;
	return 0;
}