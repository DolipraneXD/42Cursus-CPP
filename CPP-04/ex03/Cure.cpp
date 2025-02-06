/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:31:46 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/28 15:39:44 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    
}

Cure::Cure(const Cure& other) : AMateria(other.type)
{
    
}

Cure& Cure::operator=(const Cure& other)
{
    if (this != &other)
        type = other.type;
    return *this;
}

Cure::~Cure()
{
    
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

