/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:57:30 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:21:20 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++) {
        ideas[i] = "Non";
    }
    std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain &var)
{
    for (int i = 0; i < 100; i++) {
        ideas[i] = var.ideas[i];
    }
    std::cout << "Brain Copy Constructor Called" << std::endl;
}

Brain& Brain::operator=(const Brain &var)
{
    if (this != &var) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = var.ideas[i];
        }
    }
    std::cout << "Brain Copy Assignment Called" << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100) {
        ideas[index] = idea;
    } else {
        std::cout << "Invalid index, must be between 0 and 99" << std::endl;
    }
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100) {
        return ideas[index];
    } else {
        std::cout << "Invalid index, must be between 0 and 99" << std::endl;
        return "";
    }
}
