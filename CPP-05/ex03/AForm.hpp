/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:28:23 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/16 15:08:56 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string name;
        bool sign;
        const int sgrade;
        const int egrade;
    public:
        AForm();
        AForm(const std::string var, const int sg, const int eg);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string getName() const;
        int getSgrade() const;
        int getEgrade() const;
        bool getSign() const;

        void beSigned(const Bureaucrat& var);
        virtual	void execute(Bureaucrat const & executor) const = 0;

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
        class FormNotSignedException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif