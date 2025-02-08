/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:55:00 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/14 16:07:34 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // Create a ScavTrap instance
    ScavTrap scav("Guardian");

    // Attack Tests
    scav.attack("Dummy");
    scav.attack("Another Dummy");

    // Damage Tests
    scav.takeDamage(30);
    scav.takeDamage(80); // Should deplete hit points

    // Repair Tests
    scav.beRepaired(50); // Shouldn't repair because Hit is 0

    // Guard Mode Test
    scav.guardGate();

    // Destructor chaining test
    return 0;
}

