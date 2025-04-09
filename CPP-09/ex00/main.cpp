/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:55 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 10:17:35 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <cstdlib>

bool is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool check_date(std::string date)
{
    if(date.length() != 11 || date[4] != '-' || date[7] != '-')
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    std::string syear = date.substr(0, 4);
    std::string smonth = date.substr(5, 2);
    std::string sday = date.substr(8, 2);

    int year = atoi(syear.c_str());
    int month = atoi(smonth.c_str());
    int day = atoi(sday.c_str());

    if (year < 2009 || month < 1 || month > 12 || day < 1)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    int days_in_month[] = { 31, 28 + is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (day > days_in_month[month - 1])
    {
        std::cout << "Error: Invalid day " << day << " for month " << month << " => " << date << std::endl;
        return false;
    }

    return true;
}

bool valid_number(std::string& str)
{
	size_t i = 0;
	int dots = 0;

	if (str[0] == '-' || str[0] == '+')
		i = 1;

	for (; i < str.length(); i++) {
		if (str[i] == '.') {
			dots++;
			if (dots > 1)
				return false;
		}
		else if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool check_value(std::string value)
{
	if (value.empty())
		return false;
	if(!valid_number(value))
	{
		std::cout << "haha " << std::endl;
		return false;
	}
	float tmp = std::atof(value.c_str());
	if (tmp > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	if (tmp < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	return true;
}

bool is_valid(std::string line, std::string *date, float *value)
{
	std::string	first;
	std::string	second;
	size_t pos;

	pos = line.find("|");
	if (pos == std::string::npos)
	{
		std::cout << "Error: bad input => " <<  line << std::endl;
		return false;
	}
	first = line.substr(0, pos);
	second = line.substr(pos+2);
	if(!check_date(first))
		return false;
	if(!check_value(second))
		return false;
	*date = first;
	*value = atof(second.c_str());
	return true;
}

int main(int ac ,char **av)
{
	if (ac != 2)
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	std::fstream datafile ("data.csv");
	if(!datafile.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	std::fstream input(av[1]);
	if (!input.is_open())
	{
		datafile.close();
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	BitcoinExchange *BE;
	try {
		BE = new BitcoinExchange(datafile);
	} catch (std::exception &e) {
		std::cout << "Error : " << e.what() << std::endl;
	}
	std::string line;
	std::getline(input, line);
	if(line != "date | value")
	{
		std::cout << "badline" << std::endl;
		return 1;
	}

	std::string	date;
	float		value;
	while (std::getline(input, line))
	{
		if(is_valid(line, &date, &value))
		{
			std::cout << date << " => " << value << " = " << value * BE->get_price(date) << '\n';
		}
		else {
			continue;
		}
	}
	delete BE;
	input.close();
	return 0;
}