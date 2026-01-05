/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:01:05 by poverbec          #+#    #+#             */
/*   Updated: 2026/01/05 10:19:04 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <cmath>

#include <deque>

class PmergeMe
{
private:
	std::deque<int> _deque;
	std::vector<int> _vector;
	int Jacobsthal(int n);

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &object);
	PmergeMe &operator=(const PmergeMe &object);

	void fillDequeVector(std::string number);
	void SeqBeforeSorting(const PmergeMe &object);


	
	void SortingDeque(const PmergeMe &object);
	void mergeInsertionRecur(std::deque<int> &container);
	//void insertBinaryWithJakobsthal(std::vector<int> &mainChain, std::vector<int> &b_Chain, std::vector<int> JacobsthalVector);
	
	
	
	void SortingVector(const PmergeMe &object);
	
	void mergeInsertionRecur(std::vector<int> &container);
	bool isSorted(const PmergeMe &object);
	void printTimesDeque(clock_t startTime, clock_t endTime, std::deque<int> object);
	void printTimesVector(clock_t startTime, clock_t endTime ,std::vector<int> object);
};
