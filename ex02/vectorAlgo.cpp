/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorAlgo.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:21:59 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/28 20:22:31 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void PmergeMe::SortingVector(const PmergeMe &object)
{
	for (size_t value = 0; value <= _vector.size() - 2; value += 2)
	{

		if (_vector[value + 1] <= _vector[value])
			std::swap(_vector[value], _vector[value + 1]);
	}

	std::cout << "\n After vector: ";
	for (int value : object._vector)
	{
		std::cout << "[" << value << "] ";
	}

	std::cout << std::endl;
}