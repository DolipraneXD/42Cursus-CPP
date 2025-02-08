/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:01:30 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/30 10:02:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        // Create Bureaucrat with a valid grade
        Bureaucrat bureaucrat("Zaphod Beeblebrox", 1);
        // Create Presidential Pardon Form with a target
        PresidentialPardonForm form1("Arthur Dent");

        std::cout << "Created Presidential Pardon Form for " << form1.getTarget() << std::endl;
        
        // Test: Executing form without signing it
        std::cout << "\nTrying to execute without signing..." << std::endl;
        try {
            form1.execute(bureaucrat);
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Test: Signing the form and executing it
        std::cout << "\nSigning the form..." << std::endl;
        form1.beSigned(bureaucrat);
        std::cout << "Form signed!" << std::endl;

        // Try to execute after signing
        std::cout << "\nTrying to execute after signing..." << std::endl;
        form1.execute(bureaucrat);

        // Test: Bureaucrat with too low grade to execute
        Bureaucrat lowGradeBureaucrat("Trillian", 150);
        std::cout << "\nTrying to execute with a bureaucrat of low grade..." << std::endl;
        try {
            form1.execute(lowGradeBureaucrat);
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // Test: Copy constructor
        std::cout << "\nTesting copy constructor..." << std::endl;
        PresidentialPardonForm form2(form1);
        form2.execute(bureaucrat);

        // Test: Assignment operator
        std::cout << "\nTesting assignment operator..." << std::endl;
        PresidentialPardonForm form3("Ford Prefect");
        form3 = form1;
        form3.execute(bureaucrat);

        // Test: Creating form with invalid bureaucrat grade
        std::cout << "\nTesting form with invalid grade..." << std::endl;
        Bureaucrat invalidBureaucrat("Zaphod Beeblebrox", 151);
        try {
            PresidentialPardonForm invalidForm("Zaphod Beeblebrox");
            invalidForm.beSigned(invalidBureaucrat);
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Main caught exception: " << e.what() << std::endl;
    }

    return 0;
}
