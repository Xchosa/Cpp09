/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:01:05 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/29 10:26:47 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

#include <deque>

class PmergeMe
{
private:
	std::deque<int> _deque;
	std::vector<int> _vector;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &object);
	PmergeMe &operator=(const PmergeMe &object);

	void fillDequeVector(std::string number);
	void SeqBeforeSorting(const PmergeMe &object);


	
	void SortingDeque(const PmergeMe &object);
	void mergeInsertionRecur(std::deque<int> &container);
	
	
	
	void SortingVector(const PmergeMe &object);

	bool isSorted(const PmergeMe &object);
	void printTimesDeque(clock_t startTime, clock_t endTime, const PmergeMe &object);
	void printTimesVector(clock_t startTime, clock_t endTime , const PmergeMe &object);
};