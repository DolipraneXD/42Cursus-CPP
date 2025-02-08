/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:02:12 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/10 16:58:38 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("unnamed")
{
    Hit = 100;
    Energy = 50;
    Attack = 20;
    std::cout << "ScavTrap Unnamed Constructor: Ready for action!" << std::endl;
}


ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	Hit = 100;
	Energy = 50;
	Attack = 20;

	std::cout << "ScavTrap " << Name << " Ready to play " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& var) : ClapTrap(var)
{
	std::cout << "ScavTrap " << Name << " hes been Copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& var)
{
	if (this == &var)
		return (*this);
	ClapTrap::operator=(var);
	std::cout << "ScavTrap " << Name << " has been assigned" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " out for good" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (Hit <= 0 || Energy <= 0)
	{
		std::cout << "ScavTrap " << Name << " cannot attack. No hit points or energy left!" << std::endl;
		return ;
	}
	Energy--;
	std::cout << "ScavTrap " << Name << " viciously attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}
