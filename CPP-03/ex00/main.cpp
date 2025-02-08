/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:55:00 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/14 15:59:55 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    // Create a ClapTrap
    ClapTrap clap1("Clap 1");

    // Test attacking
    clap1.attack("Target Dummy");
    clap1.attack("Another Dummy");

    // Test taking damage
    clap1.takeDamage(5);
    clap1.takeDamage(7);

    // Test repairing
    clap1.beRepaired(5);
    clap1.attack("Target After Damage");

    // Create a second ClapTrap
    ClapTrap clap2("Clap 2");
    clap2.attack("Dummy");
    clap2.takeDamage(3);
    clap2.beRepaired(5);
    clap2.beRepaired(10);

    return 0;
}
