/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:04:42 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/09 11:26:35 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <exception>
#include <new>

template<class T>Array<T>::Array() : a(NULL), _size(0)
{

}

template<class T>Array<T>::Array(unsigned int n)
{
	try{
		a = new T[n];
		_size = n;
	}catch(std::exception &e)
	{
		_size = 0;
		a = NULL;
		std::cout << e.what() << std::endl;
	}
}

template<class T>Array<T>::Array(const Array& other)
{
	try{
		a = new T[other._size];
		_size = other._size;
	}catch(std::exception &e)
	{
		_size = 0;
		a = NULL;
		std::cout << e.what() << std::endl;
	}
	for (unsigned int i = 0; i < _size; i++)
	{
		a[i] = other.a[i];
	}
}

template<class T>Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
    {
		try{

			delete[] a;
			size = other.size;
			if(_size > 0)
				a = new T[_size];
			else
				a = NULL;
			for (unsigned int i = 0; i < _size; i++)
			{
				a[i] = other.a[i];
			}
		}catch(std::exception &e)
		{
			_size = 0;
			a = NULL;
			std::cout << e.what() << std::endl;
		}
    }
    return (*this);
}

template<class T>Array<T>::~Array()
{
    delete[] a;
}

template<class T> T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return a[index];
}

template<class T> const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return a[index];
}

template<class T> unsigned int Array<T>::size() const
{
    return _size;
}