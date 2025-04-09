/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:06:17 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/18 13:34:18 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <stack>
# include <iostream>
# include <string>
# include <exception>
#include <sstream>

class RPN
{
	private:
		std::stack<double> st;
		bool is_op(char op);
		void do_math(char op);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		double calculator(const std::string &av);
};