/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:41 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/12 11:10:50 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
#include "Form.hpp"

class Form;
class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        
    public:
        Bureaucrat();
        Bureaucrat(const std::string& var, int gvar);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        const std::string getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();
        
        void signForm(Form& form);

    public:
        class GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            public:
                const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif