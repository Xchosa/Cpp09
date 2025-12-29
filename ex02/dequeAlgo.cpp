/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeAlgo.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/29 10:26:36 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// pairwise comparison [n/2] if odd => leave last element out
// sort [n/2] larger numbers -> by merge insertion
//  insert remaing bs in into main-chain a -> by binary insertion

// smallest first
// dublicates next to each
// 2 < 2
// -> not sort

// 8 9 1 0 50 60 2 3 4 1 10 11 98 78 23
// 8 9 1 0 50 60 2 3 4 1 10 11 98 78 23 21

// [ 9]

void PmergeMe::SortingDeque(const PmergeMe &object)
{

	std::deque<int> tmpDeque = object._deque;

	
	
	mergeInsertionRecur(tmpDeque);
	// sort a_chain and make the same move with b stack;
	
	
	//int jabcobstal(n);
	//std::cout << std::endl;

	std::cout << "\n After Deque: ";
	for (size_t value = 0; value < object._deque.size(); value++)
	{
		std::cout << "[" << value << "] ";
	}
	// recursive sortieren mit jakobstahl folge
	_deque = tmpDeque;
	
}




void PmergeMe::mergeInsertionRecur(std::deque<int> &container)
{
	if(container.size() <= 1)
		return;

	std::deque<int> a_chain;
	std::deque<int> b_chain;

	for (size_t i = 0; i <= container.size() - 2; i += 2)
	{
		int first = container[i];
		int second = container[i + 1];

		if (first > second)
		{
			a_chain.emplace_back(first);
			b_chain.emplace_back(second);
		}
		else
		{
			a_chain.emplace_back(second);
			b_chain.emplace_back(first);
		}
	}
	if (container.size() % 2 == 1)
        b_chain.emplace_back(container.back());


	std::cout << "\n A Chain: ";
	for (size_t value = 0; value < a_chain.size(); value++)
	{
		std::cout << "[" << a_chain[value] << "] ";
	}
	std::cout << "\n B Chain: ";
	for (size_t value = 0; value < b_chain.size(); value++)
	{
		std::cout << "[" << b_chain[value] << "] ";
	}
	std::cout << std::endl;
	
	// call algo rekursive
	
	mergeInsertionRecur(container);
	std::cout << "a1: " <<container[0] << std::endl;

	for( int value : b_chain)
	{
		auto pos = std::lower_bound(a_chain.begin(), a_chain.end(), value);
		a_chain.insert(pos, value);
	}

	container = a_chain;
	
}
