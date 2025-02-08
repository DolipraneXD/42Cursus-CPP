/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:36:52 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/01 13:36:56 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string name;
        bool sign;
        const int sgrade;
        const int egrade;
    public:
        Form();
        Form(const std::string var, const int sg, const int eg);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string getName() const;
        int getSgrade() const;
        int getEgrade() const;
        bool getSign() const;

        void beSigned(const Bureaucrat& var);

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

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif