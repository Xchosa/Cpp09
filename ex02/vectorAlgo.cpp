/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAlgo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:59 by poverbec          #+#    #+#             */
/*   Updated: 2026/01/02 12:48:09 by poverbec         ###   ########.fr       */
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

	std::vector<int> mainChain = a_chain;

	// just enough to save one comparison
	// 2 ^k -1 same comparison as 2^(k -1)

	if (!b_chain.empty())
		mainChain.insert(mainChain.begin(), b_chain[0]);

	std::cout << "jakob sequence" << std::endl;
	std::vector<int> JacobsthalVector;
	size_t k = 3;
	JacobsthalVector.emplace_back(1);
	JacobsthalVector.emplace_back(1);
	for (size_t i = 1; i < b_chain.size(); i++)
	{
		size_t jValue = Jacobsthal(k);
		if (jValue < b_chain.size())
			JacobsthalVector.emplace_back(jValue);
		k++;
	}

 // filled with Jacobsthal numbers  3 5 11
	for(int value :JacobsthalVector)
	{
		std::cout << "gruppen: " << " :"<< value << std::endl;
	}
	
	//insertBinaryWithJakobsthal(mainChain, b_chain, JacobsthalVector);
	
	size_t lastJacob = 1;
	for(size_t i = 1; i< JacobsthalVector.size(); i++)
	{
		size_t currJac = JacobsthalVector[i];
		
		size_t startIdx = std::min(currJac, b_chain.size()); // out of bounds check
		for (size_t j = startIdx; j > lastJacob; --j)
		{
			int target = b_chain[j-1]; // b5 then b4 
			std::cout << "index inserted" << (j-1) << std::endl;
			

			// order ti insert [3, 2, 5, 4] 
			auto it = std::lower_bound(mainChain.begin(), mainChain.end(), target);
			mainChain.insert(it, target);
		}
		lastJacob = startIdx;
	}
	

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
	
	std::cout << "\n Main Chain : ";
	for (size_t value : mainChain)
	{
		std::cout << "[" << value << "] ";
	}

	container = mainChain;
}







































/*
for (size_t i = target_index; i >= b_chain.size(); i--)
		{
			auto posValue = std::lower_bound(main_chain.begin(), main_chain.end(), b_chain[i]);
			main_chain.insert(posValue, b_chain[i]);
		}
*/


//// 1. Jacobsthal-Indizes generieren, die innerhalb der b_chain Größe liegen
//std::vector<size_t> j_indices;
//size_t k = 3; // Wir starten bei J(3) = 3, da J(1)=1 und J(2)=1 bereits durch b0 abgedeckt sind
//while (true) {
//    size_t j_val = Jacobsthal(k);
//    if (j_val >= b_chain.size()) {
//        j_indices.push_back(b_chain.size() - 1); // Letzten Index der b_chain hinzufügen
//        break;
//    }
//    j_indices.push_back(j_val - 1); // -1, da Jacobsthal-Zahlen meist 1-basiert für Mengen gedacht sind
//    k++;
//}

//// 2. In Gruppen rückwärts einfügen
//size_t last_processed = 0; 
//for (size_t target_idx : j_indices) {
//    // Wir gehen vom aktuellen Jacobsthal-Index rückwärts bis zum Ende der letzten Gruppe
//    for (size_t i = target_idx; i > last_processed; --i) {
//        int element_to_insert = b_chain[i];
        
//        // WICHTIG: Die Binärsuche (std::lower_bound) ist hier Pflicht, 
//        // um die minimale Anzahl an Vergleichen zu garantieren.
//        // Der Suchbereich kann optimiert werden (bis zum Partner a_i), 
//        // für den Anfang reicht aber die gesamte main_chain.
//        auto it = std::lower_bound(main_chain.begin(), main_chain.end(), element_to_insert);
//        main_chain.insert(it, element_to_insert);
//    }
//    last_processed = target_idx;
//}