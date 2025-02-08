/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:46:38 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/06 16:28:40 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if(this != &other)
    {

    }
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void print_nan(int flag)
{
	std::cout << "char: impossible " <<std::endl;
	std::cout << "int: impossible " <<std::endl;
	if (flag == 0)
	{
		std::cout << "float: nanf" <<std::endl;
		std::cout << "double: nan " <<std::endl;
	}else if (flag == 1)
	{
		std::cout << "float: +inff" <<std::endl;
		std::cout << "double: +inf " <<std::endl;
	}else if (flag == 2)
	{
		std::cout << "float: -inff" <<std::endl;
		std::cout << "double: -inf " <<std::endl;
	}
}


//***************************************************************************************** */
bool is_char(const std::string& str)
{
	if (str.length() == 1 && std::isprint(str[0]) != 0 && (!std::isdigit(str[0])))
	{
		return true;
	}
	return false;
}

bool is_int(const std::string& str)
{
	if (str.empty())
		return false;

	size_t i = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;

	for (; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}

	return (str.length() > 1 || std::isdigit(str[0]));
}


bool is_float(const std::string& str)
{
	if (str.empty())
		return false;

	size_t i = 0;

	bool hdbd = false;
	bool hdad = false;
	bool hd = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i>= str.length() || !std::isdigit(str[i]))
		return false;
	while (i < str.length())
	{
		if (std::isdigit(str[i]))
		{
			if (!hd)
				hdbd = true;
			else
				hdad = true;
		}else if (str[i] == '.')
		{
			if (hd)
				return false;
			else
				hd = true;
		}else if (str[i] == 'f' && (i == str.length() - 1))
		{
			return (hdbd || hdad);
		}else
			return false;
		i++;
	}
	return false;
}

bool is_double(std::string& str)
{
	if (str.empty())
		return false;

	size_t i = 0;
	bool hdbd = false;
	bool hdad = false;
	bool hd = false;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i>= str.length() || !std::isdigit(str[i]))
		return false;
	while (i < str.length())
	{
		if(std::isdigit(str[i]))
		{
			hdbd = true;
			if (hd)
				hdad = true;
		}else if (str[i] == '.')
		{
			if (hd)
				return false;
			hd = true;
		}else
			return false;
		i++;
	}

	return hdbd && (!hd || hdad);
}

//**************************************************************************************** */
void Display_char(const std::string& str)
{
	char c;
	int i;
	float f;
	double d;

	c = str[0];
	i = static_cast <int >(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
	if (std::isprint(c) != 0)
    	std::cout << "char: '" << c << "'" << std::endl;
	else
    	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double " << d << ".0"<< std::endl;
}

void Display_int(char *str)
{
	char c;
	int i;
	float f;
	double d;
	long l;

	errno = 0;
	char *endptr;
	l = strtol(str, &endptr, 10);

	if (errno != 0 || *endptr != '\0' || str == endptr || l > INT_MAX || l < INT_MIN)
	{
		std::cout << "char: impossible" << std::endl;
    	std::cout << "int: impossible" << std::endl;
    	std::cout << "float: impossible" << std::endl;
    	std::cout << "double: impossible" << std::endl;
		return ;
	} else {
		c = static_cast <char> (l);
		if (l < 0 || l > 255)
		{
			std::cout << "char: impossible" << std::endl;
		}else if (std::isprint(c) == 0)
		{
			std::cout << "char: Non displayable" << std::endl;
		}else{
			std::cout << "char: " << c << std::endl;
		}
	}
	i = static_cast<int>(l);
	std::cout << "int: " << i << std::endl;
	f = static_cast<float>(i);
	std::cout << "float: " << f << ".0f" << std::endl;
	d = static_cast<double>(i);
	std::cout << "double: " << d << ".0" <<std::endl;

}

int count_precision(const std::string &str)
{
	int count = 0;
	size_t i = str.find('.');
	if (i == std::string::npos)
		return 0;

	i++;

	while (i < str.length() && str[i] != 'f')
	{
		count++;
		i++;
	}

	return count;
}


void Display_float(const std::string &str)
{
	errno = 0;

	char *endptr;
	float f;
	char c;
	int i;
	double d;

	f = std::strtof(str.c_str(), &endptr);
	if (errno == ERANGE || *endptr != 'f' || endptr != str.c_str() + str.length() - 1)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	c = static_cast<char>(f);
	if (f < 0 || f > 255 || std::isnan(f))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;


	i = static_cast<int>(f);
	if (f < INT_MIN || f > INT_MAX || std::isnan(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	int count = count_precision(str );

	std::cout << std::fixed << std::setprecision(count) << "float: " << f << "f" << std::endl;


	d = static_cast<double>(f);
	std::cout << std::fixed << std::setprecision(count) << "double: " << d << std::endl;

}

void Display_double(std::string& str)
{
	errno = 0;

	char *endptr;
	float f;
	char c;
	int i;
	double d;

	d = std::strtod(str.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}


	c = static_cast<char>(d);
	if (d < 0 || d > 255 || std::isnan(d))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		 std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;


	i = static_cast<int>(d);
	if (d < INT_MIN || d > INT_MAX || std::isnan(d))
		std::cout << "int: impossible"  << std::endl;
	else
		std::cout << "int: " << i << std::endl;


	int count = count_precision(str );

	f = static_cast<float>(d);
	if ( d < -FLT_MAX || d > FLT_MAX || std::isnan(d))
		std::cout << "float: impossible" << std::endl;
	else if (count > 7)
		 std::cout << std::fixed << std::setprecision(7) << "float: " << f << "f" << std::endl;
	else
		 std::cout << std::fixed << std::setprecision(count) << "float: " << f << "f" << std::endl;


	if (count < 15)
		std::cout << std::fixed << std::setprecision(count) << "double: "<< d << std::endl;
	else
		std::cout << std::fixed << std::setprecision(15) << "double: "<< d << std::endl;
}

//**************************************************************************************** */
void ScalarConverter::convert(char *str)
{
	std::string tmp = str;

	if (tmp == "nan" || tmp == "nanf")
	{
		print_nan(0);
		return ;
	}else if (tmp == "+inff" || tmp == "+inf")
	{
		print_nan(1);
		return ;
	}else if (tmp == "-inff" || tmp == "-inf")
	{
		print_nan(2);
		return ;
	}

	if (is_char(tmp) == true )
		return Display_char(tmp);
	else if (is_int(str))
		return Display_int(str);
	else if (is_float(tmp))
		return Display_float(tmp);
	else if (is_double(tmp))
		return Display_double(tmp);
	else
		std::cout << "unvalid unput" << std::endl;
}