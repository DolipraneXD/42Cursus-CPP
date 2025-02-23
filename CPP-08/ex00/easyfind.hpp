/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:34:45 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/03 14:39:24 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return "Value not found in container";
        }
};

template<typename T>
typename T::iterator easyfind(T &var, int value)
{
    typename T::iterator it = std::find(var.begin(), var.end(), value);
    if (it == var.end())
        throw NotFoundException();
    return it;
}

