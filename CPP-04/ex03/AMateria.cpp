/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:23:12 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:19:25 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria():type ("Non")
{
    
}

AMateria::AMateria(std::string const & type) : type(type) 
{
    
}

AMateria::AMateria(const AMateria &other): type(other.type)
{
    
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if(this != &other)
    {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria()
{
    
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
}
