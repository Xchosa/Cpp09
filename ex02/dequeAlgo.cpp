/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeAlgo.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/30 13:12:33 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <bits/stdc++.h>
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
	clock_t startTime;
	clock_t endTime;
	std::deque<int> tmpDeque = object._deque;
	startTime = clock();
	mergeInsertionRecur(tmpDeque);
	endTime = clock();
	// sort a_chain and make the same move with b stack;
	printTimesDeque(startTime, endTime, tmpDeque);
	
	// int jabcobstal(n);
	// std::cout << std::endl;

	std::cout << "\n After Deque: ";
	for (int value : tmpDeque)
	{
		std::cout << "[" << value << "] ";
	}
	// recursive sortieren mit jakobstahl folge
	//_deque = tmpDeque;
}

void PmergeMe::mergeInsertionRecur(std::deque<int> &container)
{
	if (container.size() <= 1)
		return;

	std::deque<std::pair<int, int>> pairs;

	int leftover = -1;

	for (size_t i = 0; i <= container.size() - 1; i += 2)
	{
		int first = container[i];
		int second = container[i + 1];

		// bigger nbr in a
		if (first > second)
		{
			pairs.push_back({first, second});
		}
		else
		{
			pairs.push_back({second, first});
		}
	}
	if (container.size() % 2 == 1)
		leftover = container.back();

	// first round winner
	std::deque<int> winner;

	// only winners/bigger numbers get called
	//  again a 2 number comparison of the winners (each winner has an atached  b number)
	for (auto &iter : pairs)
	{
		winner.emplace_back(iter.first);
	}
	
	std::cout << "winner chain" << std::endl;
	for (int value : winner)
	{
		std::cout << "["<< value << "] ";
	}
	std::cout << std::endl;
	// call algo rekursive
	mergeInsertionRecur(winner);

	// biggest nbr left, now winner chain gets rekursion pops up (see pair values) 
	// the next winner put in the a_stack -> is sorted at the end
	// each random b gets pushed into b_stack
	// bubbeling up 
	std::cout << "winner chain after sorting " << std::endl;
	for (int value : winner)
	{
		std::cout << "["<< value << "] ";
	}
	std::cout << std::endl;
	
	std::deque<int> a_chain;
	std::deque<int> b_chain;

	// structure bindings 
	std::cout << "\n pair values : ";
	for (auto [a,b] : pairs)
	{
		std::cout << "[" << a << "|" << b << "] ";
	}
	//std::deque<std::pair<int, int>> winnerPairs;

	for (int sortedVal : winner)
	{
		for (auto iter = pairs.begin(); iter != pairs.end(); iter++)
		{
			if (iter->first == sortedVal) // starts with 0 until no winner left
			{
				a_chain.emplace_back(iter->first);
				b_chain.emplace_back(iter->second);
				
				pairs.erase(iter);
				break;
			}
		}
	}

	//std::cout << "\n pair values : ";
	//for (auto [a,b] : pairs)
	//{
	//	std::cout << "[" << a << "|" << b << "] ";
	//}

	std::deque<int> mainChain = a_chain;
	if(!b_chain.empty())
	{
		mainChain.insert(mainChain.begin(), b_chain[0]);
	}
	// add after each recursive iteration the leftover in the b chain
	if (leftover != -1)
		b_chain.emplace_back(leftover);

	std::cout << "\n A Chain : ";
	for (size_t value : a_chain)
	{
		std::cout << "[" << value << "] ";
	}
	std::cout << "\n B Chain : ";
	for (size_t value : b_chain)
	{
		std::cout << "[" << value << "] ";
	}
	std::cout << std::endl;
	

	// simplyfied lowerbounds only works on sorted containers...
	for(size_t i = 1; i < b_chain.size() ; i++)
	{
		auto pos = std::lower_bound(mainChain.begin(),mainChain.end(), b_chain[i] );
		mainChain.insert(pos, b_chain[i]);
	}
	std::cout << "\n Main Chain : ";
	for (size_t value : mainChain)
	{
		std::cout << "[" << value << "] ";
	}
	std::cout << std::endl;
	
	
	// bubbeling up
	container = mainChain;
}
