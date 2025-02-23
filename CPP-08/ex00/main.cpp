/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:34:38 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/03 14:38:10 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        int a = i * 10;
        vec.push_back(a);
    }
    
    try{
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "foud :" << *it << std::endl;
    }catch (const std::exception &e){
        std::cout << "Error :" << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 5; i++)
    {
        int a = i * 100;
        lst.push_back(a);
    }
    
    try{
        std::list<int>::iterator it = easyfind(lst, 300);
        std::cout << "foud :" << *it << std::endl;
    }catch (const std::exception &e){
        std::cout << "Error :" << e.what() << std::endl;
    }
}