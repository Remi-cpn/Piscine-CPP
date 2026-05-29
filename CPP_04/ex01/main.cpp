/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:53:37 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/28 13:00:00 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main( void )
{
	// Test 1 : tableau de 6 Animal* (3 Dog + 3 Cat), delete via Animal*
	std::cout << YELLOW << "Test 1 : Tableau d'Animal* - constructeurs et destructeurs" << RESET << std::endl;
	{
		const int size = 6;
		Animal* animals[size];

		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();

		for (int i = 0; i < size; i++)
		{
			std::cout << animals[i]->getType() << " says: ";
			animals[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	// Test 2 : deep copy Dog (copy constructor)
	std::cout << std::endl << YELLOW << "Test 2 : Deep copy Dog (copy constructor)" << RESET << std::endl;
	{
		Dog d1;
		d1.getBrain()->setIdea(0, "Chasser le facteur");

		Dog d2(d1);

		std::cout << "d1.idea[0] = " << d1.getBrain()->getIdea(0) << std::endl;
		std::cout << "d2.idea[0] = " << d2.getBrain()->getIdea(0) << std::endl;

		d2.getBrain()->setIdea(0, "Dormir");
		std::cout << "Apres modification de d2 :" << std::endl;
		std::cout << "d1.idea[0] = " << d1.getBrain()->getIdea(0) << " (inchange)" << std::endl;
		std::cout << "d2.idea[0] = " << d2.getBrain()->getIdea(0) << std::endl;
	}

	// Test 3 : deep copy Cat (operator=)
	std::cout << std::endl << YELLOW << "Test 3 : Deep copy Cat (operator=)" << RESET << std::endl;
	{
		Cat c1;
		c1.getBrain()->setIdea(0, "Renverser un verre");

		Cat c2;
		c2 = c1;

		std::cout << "c1.idea[0] = " << c1.getBrain()->getIdea(0) << std::endl;
		std::cout << "c2.idea[0] = " << c2.getBrain()->getIdea(0) << std::endl;

		c2.getBrain()->setIdea(0, "Ignorer tout le monde");
		std::cout << "Apres modification de c2 :" << std::endl;
		std::cout << "c1.idea[0] = " << c1.getBrain()->getIdea(0) << " (inchange)" << std::endl;
		std::cout << "c2.idea[0] = " << c2.getBrain()->getIdea(0) << std::endl;
	}

	return 0;
}
