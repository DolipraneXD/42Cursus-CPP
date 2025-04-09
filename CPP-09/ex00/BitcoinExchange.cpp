/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:40:03 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 10:20:50 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

BitcoinExchange::BitcoinExchange()
{
	std::cout << "I need data.csv file to work with ;)" << std::endl;
}
BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : data(other.data)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		data = other.data;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(std::fstream &datafile)
{
	std::string	line;
	std::string	date;
	std::string	price;
	float		pricef;
	size_t		pos;

	while (std::getline(datafile, line))
	{
		pos = line.find(',');
		if(pos != std::string::npos)
		{
			date = line.substr(0, pos);
			price = line.substr(pos+1);
			pricef = std::strtof(price.c_str(), NULL);
			data.insert(std::pair<std::string, float>(date, pricef));
		}
	}
	datafile.close();
}

float BitcoinExchange::get_price(std::string date)
{
	float value;
    std::map<std::string, float>::iterator iter;

    iter = data.lower_bound(date);
    if (iter == data.end() || iter->first != date)
    {
        if (iter != data.begin())
        {
            iter--;
            value = iter->second;
        }
    }
    else
    {
       value = iter->second;
    }
	return value;
}

