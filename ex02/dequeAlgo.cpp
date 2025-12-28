/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeAlgo.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:04 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/28 21:22:55 by poverbec         ###   ########.fr       */
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

	template <typename T>
	using ThreeD = std::deque<std::deque<std::deque<T>>>;
	// if (_deque.size() < 6)
	//	std::cout << "\n sorting less than 6: ";

	for (size_t i = 0; i <= _deque.size(); i ++)
	{

		ThreeD[i][0] = deque[i];
			
	}
	
	for (size_t i = 0; i <= ThreeD[0].size(); i++)

	
	size_t maxPairSize = _dequ.size()/2 
	size_t pairSize = 1
	
	for (size_t i = 0; i <= ThreeD[i].size(); i++)
	{
		for (size_t j = 0; j <= ThreeD[i][j].size(); j++)
		{
			if(ThreeD[i][j.last()]) > ThreeD[i+1][j.last()]
			{
				std::swap(_vector[value], _vector[value + 1]);
			}
			ThreeD[i][j] = 
		}
	}
	

	

	std::cout << "\n After Deque: ";
	for (size_t value = 0; value < object._deque.size() ; value++)
	{
		std::cout << "[" << value << "] ";
	}
	std::cout << std::endl;


	
}

void mergeInsertion(const PmergeMe &object)
{
	template <typename T>
	using ThreeD = std::vector<std::vector<std::vector<T>>>;
}

