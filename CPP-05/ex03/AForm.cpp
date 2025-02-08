/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:40:29 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/01 13:40:30 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>

AForm::AForm():name("unnamed") , sign(0), sgrade(150), egrade(150)
{

}

AForm::AForm(const std::string var, const int sg, const int eg):name(var),sign(0) ,sgrade(sg), egrade(eg)
{
    if(sg < 1 || eg < 1)
    {
        throw GradeTooHighException();
    }
    if(sg > 150 || eg > 150)
    {
        throw GradeTooLowException();
    }
}

AForm::AForm(const AForm& other):name(other.name), sign(other.sign), sgrade(other.sgrade), egrade(other.egrade)
{

}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        sign = other.sign;
    }
    return (*this);
}

AForm::~AForm()
{

}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too hight");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return ("Form is not signed and cannot be executed!");
}

const std::string AForm::getName() const
{
    return (name);
}

bool AForm::getSign() const
{
    return (sign);
}

int AForm::getEgrade() const
{
    return (egrade);
}

int AForm::getSgrade() const
{
    return (sgrade);
}

void AForm::beSigned(const Bureaucrat& var)
{
    if(var.getGrade() > sgrade)
    {
        throw GradeTooLowException();
    }
    sign = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
   out << "form " << form.getName() << ", Signed: " << (form.getSign() ? "yes" : "no")
       << ", grade required to sign: " << form.getSgrade()
       << ", grade required to execute: " << form.getEgrade();
    return (out);
}