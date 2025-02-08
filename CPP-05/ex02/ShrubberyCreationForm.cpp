/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:57 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/30 10:07:39 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), target("NON")
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) :AForm(other), target(other.target)
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    
}

const std::string ShrubberyCreationForm::getTarget() const
{
    return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getEgrade()) {
        throw AForm::GradeTooLowException();
    }
    
    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile.is_open())
    {
        throw std::ios_base::failure("Failed to open file");
    }

    outfile << "        _-_              _-_              _-_  \n";
    outfile << "     /~~   ~~\\       /~~~ ~~~\\       /~~   ~~\\  \n";
    outfile << "  /~~         ~~\\   /~~     ~~\\   /~~       ~~\\  \n";
    outfile << " /               \\ /         *  \\ /           \\  \n";
    outfile << "{                 }{  *          }{  *   *     }\n";
    outfile << "{  *      *       }{       *     }{       *    }\n";
    outfile << " \\  _-       -_  /  \\  _-     -_  /  \\  _-   -_  /  \n";
    outfile << "   ~  \\\\   //  ~     ~  \\\\ //  ~     ~  \\\\ //  ~  \n";
    outfile << "        | |              | |              | |  \n";
    outfile << "        | |              | |              | |  \n";
    outfile << "        ~ ~              ~ ~              ~ ~  \n";

    outfile.close();
    std::cout << "Shrubbery created successfully at " << target + "_shrubbery" << std::endl;
    
}