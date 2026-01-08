/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAlgo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:59 by poverbec          #+#    #+#             */
/*   Updated: 2026/01/08 14:05:54 by poverbec         ###   ########.fr       */
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
	std::cout << "\nAfter: ";
	for (int value : tmpVector)
	{
		std::cout << "[" << value << "] ";
	}
	std::cout << std::endl;

	printTimesVector(startTime, endTime, tmpVector);

	// std::cout << "\n After vector: ";
	// for (int value : tmpVector)
	//{
	//	std::cout << "[" << value << "] ";
	// }
	// std::cout << std::endl;

	// object._vector = tmpVector;
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
	// std::cout << "pairs size: " << pairs.size() << " | winner size: " << winner.size() << std::endl;
	// std::cout << "winner chain" << std::endl;
	// for (int value : winner)
	//{
	//	std::cout << "["<< value << "] ";
	// }
	// std::cout << std::endl;
	mergeInsertionRecur(winner);

	std::vector<int> a_chain;
	std::vector<int> b_chain;

	// std::cout << "bubbling up pairs" << std::endl;
	// for (auto iter : pairs)
	//{
	//	std::cout << "[" << iter.first << "|" << iter.second << "]";
	// }
	// std::cout << std::endl;

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

	std::vector<int> mainChain = a_chain;

	// just enough to save one comparison
	// 2 ^k -1 same comparison as 2^(k -1)

	if (!b_chain.empty())
		mainChain.insert(mainChain.begin(), b_chain[0]);

	// std::cout << "jakob sequence" << std::endl;
	std::vector<int> JacobsthalVector;
	size_t k = 3;
	while (1)
	{
		size_t jValue = Jacobsthal(k);
		if (jValue >= b_chain.size())
		{
			JacobsthalVector.emplace_back(b_chain.size());
			break;
		}
		JacobsthalVector.emplace_back(jValue);
		k++;
	}

	// filled with Jacobsthal numbers  3 5 11
	// for (int value : JacobsthalVector)
	//{
	//	std::cout << "gruppen: " << " :" << value << std::endl;
	//}

	// if jacVecotr = 3 -> insert 3 then 2
	// if jacvec = 5 -> insert 5 then 4
	// if jacvec = 11 -> insert 11 , 10 , 9,8 ,7,6

	// insertBinaryWithJakobsthal(mainChain, b_chain, JacobsthalVector);

	size_t lastJacob = 1;
	int insertedEl = 1;
	for (size_t i = 0; i < JacobsthalVector.size(); i++)
	{
		size_t currJac = JacobsthalVector[i];
		size_t startIdx = std::min(currJac, b_chain.size()); // out of bounds check
		

		for (size_t j = startIdx; j > lastJacob; j--)
		{
			int target = b_chain[j - 1];

			// order insert [3, 2, 5, 4] jumps to the complicated first (first 5 then 4 )
		
			size_t Limit = mainChain.size();
			// leftover alwarys needs the hole chain
			if (j -1 < a_chain.size())
			{
				Limit = std::min((size_t)(j - 1 + insertedEl), mainChain.size());
			}
			auto it = std::lower_bound(mainChain.begin(),mainChain.begin() + Limit, target);
			
			mainChain.insert(it, target);
			insertedEl++;
		}
		lastJacob = startIdx;
	}

	// for strict Ford Johnson -> make the range smaller -> not always manChain.end();
	// only search until each pair -> so b_k <=  a_k not

	// std::cout << "\n A Chain : ";
	// for (size_t value : a_chain)
	//{
	//	std::cout << "[" << value << "] ";
	// }
	// std::cout << "\n B Chain : ";
	// for (size_t value : b_chain)
	//{
	//	std::cout << "[" << value << "] ";
	// }
	// std::cout << std::endl;

	// std::cout << "\n Main Chain : ";
	// for (size_t value : mainChain)
	//{
	//	std::cout << "[" << value << "] ";
	// }
	// std::cout << std::endl;

	container = mainChain;
	//container = std::move(mainChain);
}
