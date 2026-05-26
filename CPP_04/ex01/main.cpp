/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:53:37 by rcompain          #+#    #+#             */
/*   Updated: 2026/05/26 15:06:08 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define YELLOW  "\033[33m"
#define DIM		"\033[2m"
#define RESET	"\033[0m"

int main( void )
{
	//Test 1. Main du sujet
	std::cout << YELLOW << "Test 1 : Main du sujet" << RESET << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	//Test 2. Polymorphisme - tableau mixte d'Animal*
	std::cout << std::endl << YELLOW << "Test 2 : Tableau d'Animal* (polymorphisme)" << RESET << std::endl;
	{
		const int size = 6;
		Animal* animals[size];

		for (int i = 0; i < size / 2; i++)
			animals[i] = new Dog();
		for (int i = size / 2; i < size; i++)
			animals[i] = new Cat();

		for (int i = 0; i < size; i++)
		{
			std::cout << animals[i]->getType() << " says : ";
			animals[i]->makeSound();
		}
		for (int i = 0; i < size; i++)
			delete animals[i];
	}

	//Test 3. Copie (copy constructor et operator=)
	std::cout << std::endl << YELLOW << "Test 3 : Copie" << RESET << std::endl;
	{
		Dog d1;
		Dog d2(d1);
		Dog d3;
		d3 = d1;

		std::cout << "d1 type: " << d1.getType() << std::endl;
		std::cout << "d2 type: " << d2.getType() << std::endl;
		std::cout << "d3 type: " << d3.getType() << std::endl;
		d1.makeSound();
		d2.makeSound();
		d3.makeSound();
	}

	//Test 4. WrongAnimal / WrongCat - sans virtual
	std::cout << std::endl << YELLOW << "Test 4 : WrongAnimal / WrongCat (sans virtual)" << RESET << std::endl;
	{
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat  = new WrongCat();

		std::cout << "WrongCat via WrongAnimal* : ";
		wrongCat->makeSound();
		std::cout << "WrongAnimal direct        : ";
		wrongMeta->makeSound();

		delete wrongMeta;
		delete wrongCat;
	}

	//Test 5. Comparaison Animal (virtual) vs WrongAnimal (non-virtual)
	std::cout << std::endl << YELLOW << "Test 5 : Comparaison virtual vs non-virtual" << RESET << std::endl;
	{
		const Animal*      realCat  = new Cat();
		const WrongAnimal* fakeCat  = new WrongCat();

		std::cout << "Cat via Animal*      : ";
		realCat->makeSound();
		std::cout << "WrongCat via WrongAnimal* : ";
		fakeCat->makeSound();

		delete realCat;
		delete fakeCat;
	}

	return 0;
}
