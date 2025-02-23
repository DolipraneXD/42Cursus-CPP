/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:41:41 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:05 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():maxsize(0)
{
    std::cout << "nothing happened if u didn't give a valid size value " << std::endl;
}

Span::Span(unsigned int N):maxsize(N)
{
    vac.reserve(N);
}

Span::Span(const Span& other):vac(other.vac) , maxsize(other.maxsize)
{
    
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        vac = other.vac;
        maxsize = other.maxsize;
    }
    return *this;
}

Span::~Span()
{
    
}

void Span::addNumber(int num)
{
    if (vac.size() >= maxsize)
        throw std::overflow_error("Span is Full");
    vac.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    size_t count = std::distance(start, end);
    if (vac.size() + count > maxsize)
        throw std::overflow_error("Not enough space in Span to add all numbers.");

    vac.insert(vac.end(), start, end);
}

int Span::shortestSpan() const
{
    if (vac.size() < 2)
        throw std::logic_error("not enough numbers to calculate span.");
    
    std::vector<int> Svac = vac;
    std::sort(Svac.begin(), Svac.end());

    int minspan = Svac[1] - Svac[0];
    
    for (size_t i = 1; i < Svac.size() - 1; ++i)
    {
        int diff = Svac[i + 1] - Svac[i];
        if (diff < minspan)
            minspan = diff;
    }
    
    return (minspan);
}

int Span::longestSpan()
{
    if (vac.size() < 2)
        throw std::logic_error("not enough numbers to calculate span.");

    int max = *std::max_element(vac.begin(), vac.end());
    int min = *std::min_element(vac.begin(), vac.end());

    return (max - min);
}

void Span::print_vector()
{
    for (std::vector<int>::const_iterator it = vac.begin(); it != vac.end(); ++it)
        std::cout << "sp number is : " << *it << '\n';   
}

