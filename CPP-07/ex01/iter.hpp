/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:45:32 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/08 11:13:03 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template<typename T>
void iter(T *array, size_t length, void(*func)(T&))
{
    if (!array)
        return ;
    for(size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif