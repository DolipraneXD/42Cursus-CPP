/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:05:26 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:20:32 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() 
{
    this->type = "Dog";
    brain = new Brain();
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog &var) : Animal(var) 
{
    brain = new Brain(*var.brain);
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog& Dog::operator=(const Dog &var)
{
    if (this != &var)
    {
        Animal::operator=(var);
        delete brain;
        brain = new Brain(*var.brain);
    }
    std::cout << "Dog Copy Assignment Called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}
