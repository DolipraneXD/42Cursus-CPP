/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 13:39:58 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 10:13:48 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> data;
	public:
		BitcoinExchange();
		BitcoinExchange(std::fstream &datafile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		float get_price(std::string date);
};