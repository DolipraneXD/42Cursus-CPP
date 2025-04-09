/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:06:13 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 10:23:46 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(const RPN& other)
{
	(void) other;
}

RPN& RPN::operator=(const RPN& other)
{
	(void) other;
	return *this;
}

bool RPN::is_op(char op)
{
	return (op == '+' || op == '-' || op == '*' || op == '/');
}

void RPN::do_math(char op)
{
	if (st.size() < 2)
		throw std::runtime_error("Error");

	double b = st.top();
	st.pop();

	double a = st.top();
	st.pop();
	double n;
	switch (op) {
		case '+':
			n = a + b;
			st.push(n);
			break;
		case '-':
			n = a - b;
			st.push(n);
			break;
		case '*':
			n = a * b;
			st.push(n);
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("infinity");
			n = a / b;
			st.push(n);
			break;
	}
}

double RPN::calculator(const std::string &av)
{
	std::istringstream iss(av);
	std::string token;

	while (iss >> token)
	{
		if (token.length() != 1)
			throw std::runtime_error("Error");

		char c = token[0];
		if (std::isdigit(c))
			st.push(static_cast<double>(c - '0'));
		else if (is_op(c))
		 	do_math(c);
		else
		 	 throw std::runtime_error("Error");
	}
	if (st.size() != 1)
		throw std::runtime_error("Error");
	return st.top();
}