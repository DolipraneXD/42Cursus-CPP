/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:35:02 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 12:58:03 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <ctime>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();
		static void merge_insert_vec(std::vector<int> &vec);
		static void merge_insert_deq(std::deque<int> &deq);

};