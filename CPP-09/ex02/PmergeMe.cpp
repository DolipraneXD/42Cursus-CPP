/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:59 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 12:57:40 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe& other){(void)other;}

PmergeMe& PmergeMe::operator=(const PmergeMe& other )
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe(){}

std::vector<size_t> jacobsthal_number_v(size_t size)
{
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (1)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >=size)
			break;
		jacobsthal.push_back(next);
	}
	return (jacobsthal);
}

void PmergeMe::merge_insert_vec(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> sorted;

	size_t check = vec.size() % 2;

	for (size_t i = 0; i < vec.size() - check; i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}

	int odd = -1;
	if (check)
		odd = vec[vec.size() - 1];

	std::vector<int> large;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		large.push_back(pairs[i].first);
	}

	merge_insert_vec(large);

	sorted = large;

	if (!pairs.empty()) {
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
		sorted.insert(pos, pairs[0].second);
	}

	std::vector<size_t> jacobsthal = jacobsthal_number_v(pairs.size());

	for (size_t j = 1; j < jacobsthal.size(); j++)
	{
		for (size_t i = jacobsthal[j - 1] + 1; i <= jacobsthal[j] && i < pairs.size(); i++)
		{
			std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
			sorted.insert(pos, pairs[i].second);
		}
	}

	for (size_t i = jacobsthal.back() + 1; i < pairs.size(); i++)
	{
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
		sorted.insert(pos, pairs[i].second);
	}

	if (odd != -1)
	{
		std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
		sorted.insert(pos, odd);
	}

	vec = sorted;
}

std::deque<size_t> jacobsthal_number_d(size_t size)
{
	std::deque<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (1)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		if (next >=size)
			break;
		jacobsthal.push_back(next);
	}
	return (jacobsthal);
}

void PmergeMe::merge_insert_deq(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<std::pair<int, int> > pairs;
	std::deque<int> sorted;

	size_t check = deq.size() % 2;

	for (size_t i = 0; i < deq.size() - check; i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}

	int odd = -1;
	if (check)
		odd = deq[deq.size() - 1];

	std::deque<int> large;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		large.push_back(pairs[i].first);
	}

	merge_insert_deq(large);

	sorted = large;

	if (!pairs.empty()) {
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[0].second);
		sorted.insert(pos, pairs[0].second);
	}

	std::deque<size_t> jacobsthal = jacobsthal_number_d(pairs.size());

	for (size_t j = 1; j < jacobsthal.size(); j++)
	{
		for (size_t i = jacobsthal[j - 1] + 1; i <= jacobsthal[j] && i < pairs.size(); i++)
		{
			std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
			sorted.insert(pos, pairs[i].second);
		}
	}

	for (size_t i = jacobsthal.back() + 1; i < pairs.size(); i++)
	{
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), pairs[i].second);
		sorted.insert(pos, pairs[i].second);
	}

	if (odd != -1)
	{
		std::deque<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
		sorted.insert(pos, odd);
	}

	deq = sorted;
}