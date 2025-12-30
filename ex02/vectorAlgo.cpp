/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAlgo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/30 18:24:03 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::SortingVector(const PmergeMe &object)
{
	clock_t startTime;
	clock_t endTime;
	std::vector<int> tmpVector = object._vector;

	startTime = clock();
	mergeInsertionRecur(tmpVector);
	endTime = clock();

	printTimesVector(startTime, endTime, tmpVector);

	std::cout << "\n After vector: ";
	for (int value : tmpVector)
	{
		std::cout << "[" << value << "] ";
	}

	std::cout << std::endl;
	_vector = tmpVector;
}

void PmergeMe::mergeInsertionRecur(std::vector<int> &container)
{
	if (container.size() <= 1)
		return;

	std::vector<std::pair<int, int>> pairs;

	int leftover = -1;

	for (size_t i = 0; i <= container.size() - 2; i += 2)
	{
		if (container[i] > container[i + 1])
			pairs.push_back({container[i], container[i + 1]});
		else
			pairs.push_back({container[i + 1], container[i]});
	}

	if (container.size() % 2 != 0)
	{
		leftover = container[container.size() - 1];
	}

	std::vector<int> winner;
	for (auto iter : pairs)
	{
		winner.push_back(iter.first);
	}

	mergeInsertionRecur(winner);

	std::vector<int> a_chain;
	std::vector<int> b_chain;

	for (auto iter : pairs)
	{
		std::cout << "[" << iter.first << "|" << iter.second << "]";
	}
	std::cout << std::endl;

	for (int value : winner)
	{
		for (auto iterObj = pairs.begin(); iterObj != pairs.end(); iterObj++)
		{
			if (value == iterObj->first)
			{
				a_chain.emplace_back(iterObj->first);
				b_chain.emplace_back(iterObj->second);

				pairs.erase(iterObj);
				break;
			}
		}
	}
	if (leftover != -1)
		b_chain.emplace_back(leftover);

	std::vector<int> main_chain = a_chain;
	// nicht effektiv spar aber vergleiche, da jedes b kleiner als das folgende a sein muss

	// just enough to save one comparison
	// 2 ^k -1 same comparison as 2^(k -1)

	if (!b_chain.empty())
		main_chain.insert(main_chain.begin(), b_chain[0]);

	// jakobthal sequence

	std::vector<int> JacobsthalVector;
	size_t k = 3;
	for (size_t i = 1; i < b_chain.size(); i++)
	{
		int jValue = Jacobsthal(k);
		if (jValue < b_chain.size())
			JacobsthalVector.emplace_back(jValue);
		k++;
	}

	

// ohne lower_bound 
// in der Jakobsfolge die gruppen verteilen fuer passende zahl aus b 
	
	for (int jakobFolgeSteps : JacobsthalVector)
	{
		for (int i = 0; i < b_chain.size() ; i = jakobFolgeSteps)
		{
			if( jakobSearch(main_chain[i], b_chain[i]))
				main_chain.insert(posValue, b_chain[i]);
		}
	}
	container = main_chain;
}


// 5 7 11 			1 3  		
bool jakobSearch(int a, int b)
{
	if()
}

/*
for (size_t i = target_index; i >= b_chain.size(); i--)
		{
			auto posValue = std::lower_bound(main_chain.begin(), main_chain.end(), b_chain[i]);
			main_chain.insert(posValue, b_chain[i]);
		}
*/