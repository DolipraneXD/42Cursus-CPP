/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:40:40 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:18:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    copyTemplates(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        clearTemplates();
        copyTemplates(other);
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    clearTemplates();
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; ++i)
    {
        if (!templates[i]) {
            templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (templates[i] && templates[i]->getType() == type)
            return templates[i]->clone();
    }
    return NULL;
}

void MateriaSource::clearTemplates()
{
    for (int i = 0; i < 4; ++i)
    {
        delete templates[i];
        templates[i] = NULL;
    }
}

void MateriaSource::copyTemplates(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other.templates[i])
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = NULL;
    }
}
