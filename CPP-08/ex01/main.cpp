/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:41:47 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/03 18:09:11 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{

    try{ 
        Span sp = Span(10);
        
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        Span bigSpan(10000);
        std::srand(std::time(0));
        for (int i = 0; i < 10000; ++i)
            bigSpan.addNumber(std::rand());

        std::cout << "Big Test - Shortest Span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big Test - Longest Span: " << bigSpan.longestSpan() << std::endl;

        std::vector<int> nums ;
        nums.push_back(121);
        nums.push_back(122);
        nums.push_back(123);
        nums.push_back(124);
        sp.addNumber(nums.begin(), nums.end());
        
        sp.print_vector();
    }catch(const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;   
    }
    return 0;
}