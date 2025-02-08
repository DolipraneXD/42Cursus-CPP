/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:37:01 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/01 13:37:03 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form():name("unnamed") , sign(0), sgrade(150), egrade(150)
{

}

Form::Form(const std::string var, const int sg, const int eg):name(var),sign(0) ,sgrade(sg), egrade(eg)
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

Form::Form(const Form& other):name(other.name), sign(other.sign), sgrade(other.sgrade), egrade(other.egrade)
{

}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        sign = other.sign;
    }
    return (*this);
}

Form::~Form()
{

}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too hight");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const std::string Form::getName() const
{
    return (name);
}

bool Form::getSign() const
{
    return (sign);
}

int Form::getEgrade() const
{
    return (egrade);
}

int Form::getSgrade() const
{
    return (sgrade);
}

void Form::beSigned(const Bureaucrat& var)
{
    if(var.getGrade() > sgrade)
    {
        throw GradeTooLowException();
    }
    sign = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
   out << "Form " << form.getName() << ", Signed: " << (form.getSign() ? "yes" : "no")
       << ", grade required to sign: " << form.getSgrade()
       << ", grade required to execute: " << form.getEgrade();
    return (out);
}