/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolipranexd <dolipranexd@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:47:58 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/13 17:24:36 by dolipranexd      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

template<typename  T >
class MutantStack: public std::stack<T, std::deque <T> >
{
	public:
		MutantStack():std::stack<T>(){}
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
			{
				std::stack<T>::operator=(other);
			}
			return *this;
		}
		~MutantStack(){}

		typedef typename std::deque<T>::iterator iterator;

		iterator begin(){return this->c.begin();}
		iterator end(){return this->c.end();}

		iterator rbegin(){return this->c.rbegin();}
		iterator rend(){return this->c.rend();}
};
