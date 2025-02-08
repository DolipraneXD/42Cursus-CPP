/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:18:33 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/30 10:28:25 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
    *this = other;
}

Intern& Intern::operator=(const Intern& other )
{
    if (this != &other) 
    {

    }
    return *this;
}

Intern::~Intern()
{

}

const char* Intern::UnknownFormException::what() const throw()
{
    return "Intern cannot create form: Unknown form type";
}

AForm* createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    struct FormType
    {
        std::string name;
        AForm* (*create)(const std::string& target);
    };

    FormType formTypes[] = {
        {"robotomy request", &createRobotomyRequestForm},
        {"presidential pardon", &createPresidentialPardonForm},
        {"shrubbery creation", &createShrubberyCreationForm}
    };

    for (size_t i = 0; i < sizeof(formTypes) / sizeof(formTypes[0]); ++i)
    {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formTypes[i].create(target);
        }
    }

    throw UnknownFormException();
}
