/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:31:49 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/28 15:39:53 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
    
}

Ice::Ice(const Ice& other) : AMateria(other.type)
{
    
}

Ice& Ice::operator=(const Ice& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Ice::~Ice()
{
    
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
