/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:39 by moel-fat          #+#    #+#             */
/*   Updated: 2025/01/31 09:43:59 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 1);
        Form taxForm("Tax Form", 1, 5);

        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;

    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return (0);
}
