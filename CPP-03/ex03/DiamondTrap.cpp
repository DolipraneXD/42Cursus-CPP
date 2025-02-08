/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:00:24 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/14 10:48:53 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	Name = "";
	ClapTrap::Name = Name + "_clap_name";
	this->Hit = FragTrap::Hit;
	this->Energy = ScavTrap::Energy;
	this->Attack = FragTrap::Attack;
	std::cout << "DiamondTrap Default Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& var): ClapTrap(var + "_clap_name"), FragTrap(), ScavTrap()
{
	Name = var;
	ClapTrap::Name = var + "_clap_name";
	this->Hit = FragTrap::Hit;
	this->Energy = ScavTrap::Energy;
	this->Attack = FragTrap::Attack;
	std::cout << "DiamondTrap " << Name << " Constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& var): ClapTrap(var), FragTrap(var), ScavTrap(var)
{
	Name = var.Name;
	std::cout << "DiamondTrap Copy Constructor called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& var)
{
	if (this != &var)
	{
		ClapTrap::operator=(var);
		Name = var.Name;
	}
	std::cout << "DiamondTrap Copy Assignment Operator called!" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << Name << " Destructor called!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}
