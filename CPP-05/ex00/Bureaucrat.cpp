/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:44 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/10 15:41:21 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name("un named"), grade(150)
{
    
}

Bureaucrat::Bureaucrat(const std::string& var, int gvar):name(var)
{
    if (gvar > 150)
    {
       throw GradeTooLowException();
    }else if (gvar < 1)
    {
       throw GradeTooHighException();
    }
    grade = gvar;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):name(other.name), grade(other.grade)
{
       
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    
}

 
const std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::IncrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::DecrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too hight");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat Grade is  " << bureaucrat.getGrade();
    return (out);
}