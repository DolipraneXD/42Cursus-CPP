/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:58:18 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/30 10:04:15 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("non")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45), target(target)
{
    
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target)
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

const std::string RobotomyRequestForm::getTarget() const 
{
    return (target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getEgrade()) {
        throw AForm::GradeTooLowException();
    }

    std::cout << "*Drilling noises*" << std::endl;
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "!" << std::endl;
}