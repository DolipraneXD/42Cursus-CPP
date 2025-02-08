/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:52:36 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/14 15:59:11 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap() : Name("Unnamed"), Hit(10), Energy(10), Attack(0)
{
    std::cout << "ClapTrap " << Name << " has been created (default constructor)." << std::endl;
}

// Parameterized Constructor
ClapTrap::ClapTrap(const std::string& name) : Name(name), Hit(10), Energy(10), Attack(0)
{
    std::cout << "ClapTrap " << Name << " is ready for action!" << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap& other) : Name(other.Name), Hit(other.Hit), Energy(other.Energy), Attack(other.Attack)
{
    std::cout << "ClapTrap " << Name << " has been copied!" << std::endl;
}

// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " is out of action!" << std::endl;
}

// Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        Name = other.Name;
        Hit = other.Hit;
        Energy = other.Energy;
        Attack = other.Attack;
    }
    std::cout << "ClapTrap " << Name << " has been assigned!" << std::endl;
    return *this;
}

// Attack Function
void ClapTrap::attack(const std::string& target)
{
    if (Energy == 0 || Hit == 0)
    {
        std::cout << "ClapTrap " << Name << " cannot attack. Not enough energy or hit points!" << std::endl;
        return;
    }

    Energy--;
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
}

// Take Damage Function
void ClapTrap::takeDamage(unsigned int amount)
{
    if (Hit == 0)
    {
        std::cout << "ClapTrap " << Name << " cannot take damage. Already at 0 hit points!" << std::endl;
        return;
    }

    if (amount >= Hit)
        Hit = 0;
    else
        Hit -= amount;

    std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage! Hit points now: " << Hit << std::endl;
}


// Be Repaired Function
void ClapTrap::beRepaired(unsigned int amount)
{
    if (Energy == 0)
    {
        std::cout << "ClapTrap " << Name << " cannot repair. Not enough energy!" << std::endl;
        return;
    }

    if (Hit == 0)
    {
        std::cout << "ClapTrap " << Name << " cannot repair. Already at 0 hit points!" << std::endl;
        return;
    }

    Energy--;
    Hit += amount;
    std::cout << "ClapTrap " << Name << " repairs " << amount << " hit points! Hit points now: " << Hit << std::endl;
}

