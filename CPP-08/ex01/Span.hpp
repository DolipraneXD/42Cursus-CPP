/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:41:43 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:08 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <list>

class Span
{
    private:
        std::vector<int> vac;
        unsigned int maxsize;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        void addNumber(int num);
        void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
        int shortestSpan()const;
        int longestSpan();
        void print_vector();
        
};