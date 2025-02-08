/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:59:54 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/10 18:07:09 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

// Call the default constructor of ClapTrap
FragTrap::FragTrap() : ClapTrap()
{
    Hit = 100;
    Energy = 100;
    Attack = 30;
    std::cout << "FragTrap Default Constructor: An unnamed FragTrap is born!" << std::endl;
}


FragTrap::FragTrap(const FragTrap& var) : ClapTrap(var)
{
	std::cout << "FragTrap " << Name << " has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& var)
{
	if (this == &var)
		return (*this);
	ClapTrap::operator=(var);
	std :: cout << "FragTrap " << Name << " has been assigned" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std :: cout << "FragTrap " << Name << " is out for Good " << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	Hit = 100;
	Energy = 100;
	Attack = 30;
	std::cout << "FragTrap " << Name << " Ready To play" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (Hit <= 0 || Energy <= 0)
	{
		std::cout << "FragTrap " << Name << " Has no energy to Attack" << std::endl;
		return ;
	}

	Energy--;
	std::cout << "FragTrap " << Name << " attacks " << target << ", causing " << Attack << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << Name << " is requesting a high five! ✋" << std::endl;
}
