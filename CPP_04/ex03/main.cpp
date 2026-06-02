/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcompain <rcompain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:21:10 by rcompain          #+#    #+#             */
/*   Updated: 2026/06/02 12:50:01 by rcompain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

int main( void )
{
	// Test 1 : test officiel du sujet
	std::cout << YELLOW << "Test 1 : test officiel du sujet" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	// Test 2 : inventaire plein
	std::cout << YELLOW << "Test 2 : inventaire plein" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* hero = new Character("hero");
		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		AMateria* rejected = src->createMateria("ice");
		hero->equip(rejected);
		delete rejected;

		delete hero;
		delete src;
	}

	// Test 3 : index invalide
	std::cout << YELLOW << "Test 3 : index invalide" << RESET << std::endl;
	{
		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");

		hero->use(0, *target);
		hero->use(42, *target);
		hero->unequip(0);
		hero->unequip(42);

		delete hero;
		delete target;
	}

	// Test 4 : unequip puis re-equip
	std::cout << YELLOW << "Test 4 : unequip puis re-equip" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");

		hero->equip(src->createMateria("ice"));
		hero->equip(src->createMateria("cure"));
		hero->use(0, *target);
		hero->unequip(0);
		hero->equip(src->createMateria("cure"));
		hero->use(0, *target);

		delete hero;
		delete target;
		delete src;
	}

	// Test 5 : deep copy de Character
	std::cout << YELLOW << "Test 5 : deep copy Character" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character* a = new Character("A");
		a->equip(src->createMateria("ice"));
		a->equip(src->createMateria("cure"));

		Character* b = new Character(*a);
		ICharacter* target = new Character("target");

		b->use(0, *target);
		delete a;
		b->use(1, *target);

		Character* c = new Character("C");
		*c = *b;
		delete b;
		c->use(0, *target);

		delete c;
		delete target;
		delete src;
	}

	// Test 6 : deep copy de MateriaSource
	std::cout << YELLOW << "Test 6 : deep copy MateriaSource" << RESET << std::endl;
	{
		MateriaSource* src1 = new MateriaSource();
		src1->learnMateria(new Ice());
		src1->learnMateria(new Cure());

		MateriaSource* src2 = new MateriaSource(*src1);
		delete src1;

		ICharacter* hero = new Character("hero");
		ICharacter* target = new Character("target");
		hero->equip(src2->createMateria("ice"));
		hero->equip(src2->createMateria("cure"));
		hero->use(0, *target);
		hero->use(1, *target);

		delete hero;
		delete target;
		delete src2;
	}

	// Test 7 : type inconnu dans createMateria
	std::cout << YELLOW << "Test 7 : type inconnu" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "createMateria(\"fire\") retourne NULL : OK" << std::endl;

		ICharacter* hero = new Character("hero");
		hero->equip(unknown);
		delete hero;
		delete src;
	}

	// Test 8 : destruction via pointeur d'interface
	std::cout << YELLOW << "Test 8 : delete via ICharacter*" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* hero = new Character("hero");
		hero->equip(src->createMateria("ice"));

		delete hero;
		delete src;
	}

	return 0;
}