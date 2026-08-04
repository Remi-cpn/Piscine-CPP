/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:48:32 by rcompain          #+#    #+#             */
/*   Updated: 2026/08/04 12:40:35 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>

#define DIM		"\033[2m"
#define RESET   "\033[0m"

PmergeMe::PmergeMe(){
	std::cout << DIM << "Default constructor called." << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src){
	std::cout << DIM << "Copy constructor called." << RESET << std::endl;
	*this = src;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src){
	if (this != &src){
		_vectorStack = src._vectorStack;
		_listStack = src._listStack;
	}
	return *this;
}

PmergeMe::~PmergeMe(){
	std::cout << DIM << "Destructor called." << RESET << std::endl;
}

const std::vector<int> &PmergeMe::getVectorStack()const{ return _vectorStack;}
const std::list<int> &PmergeMe::getListStack()const{ return _listStack;}


bool	argValid(char *args){
	for (int i = 1; args[i]; i++){
		if (!isdigit(args[i]) && !isspace(args[i]))
			return false;
	}
	return true;
}

static void advenceJacobSthalSequence(int *posBegin, int *posEnd){
	// 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525...
	int a = *posBegin;
	*posBegin = *posEnd * 2 + *posBegin;
	*posEnd = a;
}


// ——— Utils Algo With Vector —————————————————————————————————————————————————————

void	PmergeMe::initStackVec(std::string &args){
	
	long	nbr = 0;
	int		sign = 1;
	bool	hasDigit = false;
	for (std::string::iterator it = args.begin(); it != args.end(); it++){
		if (*it == '-')
			sign *= -1;
		else if (*it != ' '){
			nbr = (nbr * 10) + *it - '0';
			hasDigit = true;
		}
		if (hasDigit && (it + 1 == args.end() || *(it + 1) == ' ')){
			if (nbr >= std::numeric_limits<int>::min() && nbr <= std::numeric_limits<int>::max())
				_vectorStack.push_back(nbr * sign);
			nbr = 0;
			sign = 1;
			hasDigit = false;
		}
	}
}

static std::vector<int>::iterator lowerBoundVec(std::vector<int>::iterator first, std::vector<int>::iterator last, const int& value, int lvl)
{
    std::vector<int>::iterator it;
    std::iterator_traits<std::vector<int>::iterator>::difference_type count, step;
    count = std::distance(first, last) / lvl;

    while (count > 0)
    {
        it = first;
        step = count / 2;
        std::advance(it, step * lvl + (lvl - 1));

        if (*it < value)
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

// ——— Algo With Vector ——————————————————————————————————————————————————————————

void	PmergeMe::algoWithVector(char *args){
	std::string str(args);
	initStackVec(str);
	recAlgoWithVector(1);
}

void	PmergeMe::recAlgoWithVector(int lvl){
// Arret de la recursive
	if (lvl * 2 > (int)_vectorStack.size()){
		return;
	}
		
//Boucle de swap
	for (size_t i = (lvl + lvl - 1); i < _vectorStack.size();)
	{
		if (_vectorStack[i] < _vectorStack[i - lvl]){
			for (int j = 0; j < lvl; j++)
				std::swap(_vectorStack[i - j], _vectorStack[i - lvl - j]);
		}
		i += lvl + lvl;
	}

	recAlgoWithVector(lvl * 2);

//Boucle d'insertion
	int range = _vectorStack.size() / lvl;
	if (range < 3)
		return ;
	std::vector<int> tmp(_vectorStack);
	_vectorStack.clear();
	
	// Main
	_vectorStack.insert(_vectorStack.end(), tmp.begin(), tmp.begin() + (lvl * 2));
	tmp.erase(tmp.begin(), tmp.begin() + (lvl * 2));
	range = lvl;
	for (std::vector<int>::iterator it = tmp.begin() + lvl; range + lvl <= (int)tmp.size(); it = it + lvl){
		_vectorStack.insert(_vectorStack.end(), it, it + lvl);
		tmp.erase(it, it + lvl);
		range += lvl;
	}

	// Insertion
	std::vector<int>::iterator it = tmp.begin();
	int count = 0;
	for (int posBegin = 1, posEnd = 1, pos = posBegin; pos * lvl <= (int)tmp.size();){
		std::vector<int>::iterator itPosBegin = it + (pos * lvl) - 1;
		std::vector<int>::iterator itRange = _vectorStack.begin() + (lvl * (pos + 1 + count));
		_vectorStack.insert(lowerBoundVec(_vectorStack.begin(), itRange, *itPosBegin, lvl), it + (lvl * pos - lvl), it + (lvl * pos));
		count++;
		pos--;
		if (pos <= posEnd){
			advenceJacobSthalSequence(&posBegin, &posEnd);
			pos = posBegin;
		}
		while (pos * lvl > (int)tmp.size() && pos >= posEnd){
			pos--;
		}
		if (pos <= posEnd)
			break;
	}
	
	// Enleve les element push dans _vectorSTack de tmp
	tmp.erase(tmp.begin(), tmp.begin() + count * lvl);

	// Le reste
	for (int i = 0; i < (int)tmp.size(); i++){
		_vectorStack.push_back(tmp[i]);
	}
}

// —————————————————————————————————————————————————————————————————————————————————————————————————

// ——— Utils Algo With List —————————————————————————————————————————————————————

void	PmergeMe::initStackLst(std::string &args){
	
	long	nbr = 0;
	int		sign = 1;
	bool	hasDigit = false;
	for (std::string::iterator it = args.begin(); it != args.end(); it++){
		if (*it == '-')
			sign *= -1;
		else if (*it != ' '){
			nbr = (nbr * 10) + *it - '0';
			hasDigit = true;
		}
		if (hasDigit && (it + 1 == args.end() || *(it + 1) == ' ')){
			if (nbr >= std::numeric_limits<int>::min() && nbr <= std::numeric_limits<int>::max())
				_listStack.push_back(nbr * sign);
			nbr = 0;
			sign = 1;
			hasDigit = false;
		}
	}
}

static std::list<int>::iterator lowerBoundLst(std::list<int>::iterator first, std::list<int>::iterator last, const int& value, int lvl)
{
    std::list<int>::iterator it;
    std::iterator_traits<std::list<int>::iterator>::difference_type count, step;
    count = std::distance(first, last) / lvl;

    while (count > 0)
    {
        it = first;
        step = count / 2;
        std::advance(it, step * lvl + (lvl - 1));
        if (*it < value)
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
    return first;
}

// ——— Algo With Lst ——————————————————————————————————————————————————————————

void	PmergeMe::algoWithLst(char *args){
	std::string str(args);
	initStackLst(str);
	recAlgoWithLst(1);
}

void	PmergeMe::recAlgoWithLst(int lvl){
// Arret de la recursive
	if (lvl * 2 > (int)_listStack.size())
		return;

		
//Boucle de swap
	std::list<int>::iterator it = _listStack.begin();
	int size = _listStack.size();
	int count = lvl + lvl;
	for (std::advance(it, lvl + lvl - 1);;)
	{
		std::list<int>::iterator itk = it;
		std::advance(itk, -lvl);
		if (*it < *itk){
			for (int j = 0; j < lvl; j++){
				std::list<int>::iterator iti = it;
				std::list<int>::iterator itj = it;
				std::advance(iti, -j);
				std::advance(itj, -(lvl + j));
				int value;
				value = *iti;
				*iti = *itj;
				*itj = value;
			}
		}
		int i = 0;
		for(; i < lvl + lvl; i++){
			std::advance(it, 1);
			count++;
		}
		if (count > size)
			break;
	}
	
	recAlgoWithLst(lvl * 2);

//Boucle d'insertion
	int range = _listStack.size() / lvl;
	if (range < 3)
		return ;
	
	std::list<int> tmp(_listStack);
	_listStack.clear();

	// Main
	std::list<int>::iterator iti = tmp.begin();
	std::advance(iti, lvl * 2);
	_listStack.splice(_listStack.end(), tmp, tmp.begin(), iti);
	for (int pos = lvl; pos + lvl <= (int)tmp.size(); pos += lvl){
		std::advance(iti, lvl);
		std::list<int>::iterator itj = iti;
		std::advance(itj, lvl);
		_listStack.splice(_listStack.end(), tmp, iti, itj);
		iti = itj;
	}

	// Insertion
	it = tmp.begin();
	count = 0;
	for (int posBegin = 1, posEnd = 1, pos = posBegin; pos * lvl <= (int)tmp.size();){
		std::list<int>::iterator itPosBegin = it;
		std::advance(itPosBegin, (pos * lvl) - 1);
		std::list<int>::iterator itRange = _listStack.begin();
		std::advance(itRange, lvl * (pos + 1 + count));
		iti = it;
		std::advance(iti, lvl * pos - lvl);
		std::list<int>::iterator itj = it;
		std::advance(itj, lvl * pos);
		std::list<int>::iterator itInsert = lowerBoundLst(_listStack.begin(), itRange, *itPosBegin, lvl);
		for (int i = 0; i < lvl ; i++){
			_listStack.insert(itInsert, *iti);
			std::advance(iti, 1);
		}
		count++;
		pos--;
		if (pos <= posEnd){
			advenceJacobSthalSequence(&posBegin, &posEnd);
			pos = posBegin;
		}
		while (pos * lvl > (int)tmp.size() && pos >= posEnd){
			pos--;
		}
		if (pos <= posEnd)
			break;
	}

	// Enleve les element push dans _listStack de tmp
	std::list<int>::iterator itErase = tmp.begin();
	std::advance(itErase, count * lvl);
	tmp.erase(tmp.begin(), itErase);

	// Le reste
	_listStack.splice(_listStack.end(), tmp);
}
