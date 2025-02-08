/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:16:20 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/17 21:41:46 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int main()
{
	PhoneBook PhoneBook;
	std::string command;

	while(true)
	{
		std::cout << "pls enter :ADD, SEARCH or EXIT:";
		std::getline(std::cin, command);
		if(std::cin.eof())
        {
            std::cout << "end of line " << std::endl;
            exit(1);
        }
		else if (command == "ADD")
			PhoneBook.add();
		else if (command == "SEARCH")
			PhoneBook.search();
		else if (command == "EXIT")
			exit(0);
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}
