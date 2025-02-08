/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:19:38 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/16 17:07:08 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 25, 5), target("non")
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):AForm("PresidentialPardonForm", 25, 5), target(target)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other), target(other.target)
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

const std::string PresidentialPardonForm::getTarget() const 
{
    return (target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getEgrade()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Informs that " << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}