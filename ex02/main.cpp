/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fduzant <fduzant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:07:13 by fduzant           #+#    #+#             */
/*   Updated: 2024/04/09 12:16:59 by fduzant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <typeinfo>
#include "Base.hpp"

//Randomly create an instance of A, B or C and return it as Base pointer.
Base *generate(void)
{
	int i = rand() % 3;

	if (i == 0)
	{
		std::cout << "A created" << std::endl;
		return (new A());
	}
	else if (i == 1)
	{
		std::cout << "B created" << std::endl;
		return (new B());
	}
	else
	{
		std::cout << "C created" << std::endl;
		return (new C());
	}
}

//Print the true type of the object pointed by p : "A", "B" or "C".
void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

//Print the true type of the object referenced by p : "A", "B" or "C". Using a pointer is forbidden.
void identify(Base &p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc) {}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc) {}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc) {}
}

//Main function	that will test the functions.
int main(void) {

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base *base;

	std::cout << "-- Identifying Base * --" << std::endl;
	for (int i = 0; i < 3; i++) {

		base = generate();
		identify(base);
		delete base;
	}
	
	std::cout << std::endl << "-- Identifying Base & --" << std::endl;
	for (int i = 0; i < 3; i++) {

		base = generate();
		identify(*base);
		delete base;
	}
	
	return (0);
}