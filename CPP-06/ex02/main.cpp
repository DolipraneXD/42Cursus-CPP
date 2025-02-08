/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:23:27 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/07 11:01:20 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>


Base *generate(void)
{
	Base *tmp = NULL;
	try
	{
		srand(time(NULL));
		int number = (rand() % 3) + 1;
		switch (number)
		{
			case 1:
				tmp = new A();
				break;
			case 2:
				tmp = new B();
				break;
			case 3:
				tmp = new C();
				break;
		}
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return NULL;
	}
	return tmp;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "Type: A" << std::endl;
	}else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "Type: B" << std::endl;
	}else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "Type: C" << std::endl;
	}else
	{
		std::cout << "Type: Unknown" << std::endl;
	}
}

void identify(Base& p)
{
	try{
		A &tmp = dynamic_cast<A&>(p);
		(void)tmp;
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		B &tmp = dynamic_cast<B&>(p);
		(void)tmp;

		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try{
		C &tmp = dynamic_cast<C&>(p);
		(void)tmp;

		std::cout << "Type: C" << std::endl;
		return ;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "Type: Unknown" << std::endl;
}

int main()
{
	Base *tmp = generate();
	if (!tmp)
		return 1;

	std::cout << "point check : " << std::endl;
	identify(tmp);

	std::cout << "reference check : " << std::endl;
	identify(*tmp);

	delete (tmp);
	return 0;
}