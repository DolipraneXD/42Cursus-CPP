/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:43:39 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/01 13:34:20 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat john("John", 2);
        std::cout << john << std::endl;

        john.IncrementGrade();
        std::cout << john << std::endl;

        john.IncrementGrade();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat mike("Mike", 149);
        std::cout << mike << std::endl;

        mike.DecrementGrade();
        std::cout << mike << std::endl;

        mike.DecrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalid("Invalid", 0);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
