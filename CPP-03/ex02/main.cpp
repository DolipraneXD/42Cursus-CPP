/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:55:00 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/14 18:01:56 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
        // Create ClapTrap instance
    ClapTrap clap1("Clappy");
    clap1.attack("Target A");

    // Create ScavTrap instance
    FragTrap scav1("Scavvy");
    scav1.attack("Target B");
    scav1.takeDamage(30);
    scav1.attack("Target B");
    scav1.takeDamage(30);
    scav1.attack("Target B");
    scav1.takeDamage(30);
    scav1.beRepaired(20);
    scav1.highFivesGuys();

    // Test construction/destruction chaining
    FragTrap scav2(scav1);
    scav2.attack("Target C");

    FragTrap scav3("AnotherScav");
    scav3 = scav1;
    scav3.attack("amine");
    return 0;
}

