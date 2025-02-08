/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 09:02:49 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/04 16:13:48 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
    index = 0;
}

std::string PhoneBook::truncate(const std::string& str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::add()
{
    std::string firstname, lastname, nickname, phone_number, darkest_secret;

    while (true)
    {
        std::cout << "We are adding you to the PhoneBook. Please enter your first name:\n";
        std::getline(std::cin, firstname);

        if(std::cin.eof() || std::cin.bad())
        {
            std::cout << "end of line " << std::endl;
            exit(1);
        }
        if (firstname.empty()) {
            std::cout << "First name cannot be empty. Please enter again.\n";
            continue;
        }
        std::cout << "Now your last name:\n";
        std::getline(std::cin, lastname);
        if (lastname.empty()) {
            std::cout << "Last name cannot be empty. Please enter again.\n";
            continue;
        }
        std::cout << "And your nickname:\n";
        std::getline(std::cin, nickname);
        if (nickname.empty()) {
            std::cout << "Nickname cannot be empty. Please enter again.\n";
            continue;
        }
        std::cout << "We will need your phone number:\n";
        std::getline(std::cin, phone_number);
        if (phone_number.empty()) {
            std::cout << "Phone number cannot be empty. Please enter again.\n";
            continue;
        }
        std::cout << "For sure you have some dark secret. Tell us:\n";
        std::getline(std::cin, darkest_secret);
        if (darkest_secret.empty()) {
            std::cout << "Darkest secret cannot be empty. Please enter again.\n";
            continue;
        }
        contacts[index].setFirstName(firstname);
        contacts[index].setLastName(lastname);
        contacts[index].setNickname(nickname);
        contacts[index].setPhoneNumber(phone_number);
        contacts[index].setDarkestSecret(darkest_secret);
        index = (index + 1) % 8;
        break ;
    }
}

void PhoneBook::search()
{
    // Display header
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    // Display each contact
    for (int i = 0; i < 8; i++)
    {
        if (!contacts[i].getFirstName().empty())
        {
            std::cout << std::setw(10) << i << "|"
                      << std::setw(10) << truncate(contacts[i].getFirstName()) << "|"
                      << std::setw(10) << truncate(contacts[i].getLastName()) << "|"
                      << std::setw(10) << truncate(contacts[i].getNickname()) << std::endl;
        }
    }

    // Prompt for the index to display
    std::string tmp;
    std::cout << "Please enter the index to search for: ";
    std::getline(std::cin, tmp);

    // Validate input
    if (tmp.length() == 1 && std::isdigit(tmp[0]))
    {
        int search_index = std::atoi(tmp.c_str());
        if (search_index >= 0 && search_index < 8 && !contacts[search_index].getFirstName().empty())
        {
            std::cout << "First Name: " << contacts[search_index].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[search_index].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[search_index].getNickname() << std::endl;
            std::cout << "Phone Number: " << contacts[search_index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[search_index].getDarkestSecret() << std::endl;
        }
        else
        {
            std::cout << "Invalid index or empty contact!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input! Please enter a digit between 0 and 7." << std::endl;
    }
}
