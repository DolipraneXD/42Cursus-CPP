/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:55:00 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/09 18:43:03 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    // Create a DiamondTrap object
    std::cout << "Creating DiamondTrap with name:" << std::endl;
    DiamondTrap dt("Diamondy");

    // Test attack method
    std::cout << "\nTesting attack method:" << std::endl;
    dt.attack("Enemy");

    // Test whoAmI method
    std::cout << "\nTesting whoAmI method:" << std::endl;
    dt.whoAmI();

    // Test destructors
    std::cout << "\nExiting program to test destructors:" << std::endl;

    return 0;
}
