/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:57:50 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/08 15:35:04 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <exception>
template <class T>

class Array
{
    private:
        T *a;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        //over loaded operators
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};
#include "Array.tpp"
#endif