/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:01:30 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/01 13:40:20 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

int main()
{
    try {
        Intern someRandomIntern;

        // Test 1: Create RobotomyRequestForm
        AForm* form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *form1 << std::endl;
        delete form1;

        // Test 2: Create PresidentialPardonForm
        AForm* form2 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *form2 << std::endl;
        delete form2;

        // Test 3: Create ShrubberyCreationForm
        AForm* form3 = someRandomIntern.makeForm("shrubbery creation", "Garden");
        std::cout << *form3 << std::endl;
        delete form3;
    } catch (const std::exception& e) {
        std::cerr << "Main caught exception: " << e.what() << std::endl;
    }
}
