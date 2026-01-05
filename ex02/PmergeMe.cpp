/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2026/01/05 11:13:38 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

#include "sstream"
#include "exception"

PmergeMe::PmergeMe() : _deque(0) , _vector(0)
{
}
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe &object) : _deque(object._deque), _vector(object._vector)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &object)
{
	if (this != &object)
	{
		this->_deque = object._deque;
		this->_vector = object._vector;
	}
	return (*this);
}

// Rekusive formel (J_{n}=  J_{n-1}+2 * J_{n-2}   für (n >= 2).
// dynamic programming - each function calculated one 
// time complexity = O(n)
// auxiliary Space = O(n) // helping space

//dp[0]=0 → dp[1]=1 → dp[2]=1 → dp[3]=3 → dp[4]=5 → dp[5]=11
int PmergeMe::Jacobsthal(int n)
{
	if (n == 0)
		return 0;
	// base case
	if (n == 1)
		return 1;
	// recursive step.
	
	int J[n + 1];
	J[0]= 0;
	J[1] = 1;
	for( int i = 2; i <= n ; i++) // n >=2
	{
		J[i] = J[i -1] + 2 * J[i-2];
	}
	return J[n];
}


//void PmergeMe::insertBinaryWithJakobsthal(std::vector<int> &mainChain, std::vector<int> &b_Chain, std::vector<int> JacobsthalVector)
//{
//	if(b_Chain.empty())
//		return;
//	size_t lastJacob = 1;
//	for(size_t i = 1; i< JacobsthalVector.size(); i++)
//	{
//		size_t currJac = JacobsthalVector[i];
		
//		size_t startIdx = std::min(currJac, b_Chain.size());
//		for (size_t j = startIdx; j > lastJacob; i--)
//		{
//			int target = b_Chain[j-1];
//			std::cout << "index inserted" << (j-1) << std::endl;
			
//			auto it = std::lower_bound(mainChain.begin(), mainChain.end(), target);
//			mainChain.insert(it, target);
//		}
//		lastJacob = startIdx;
//	}	
	
//}
bool checkValid(std::string number)
{
	std::size_t invalidchar = number.find_first_not_of("1234567890");
	if (invalidchar != std::string::npos)
	{
		std::cout << "Error: " << number[invalidchar];
		std::cout << " at position " << invalidchar << '\n';
		return false;
	}
	return true;
}
void PmergeMe::fillDequeVector(std::string number)
{

	int token;
	try
	{
		token = stoi(number);
		if (token < 0)
			throw std::invalid_argument("Error invalid input");
		_deque.emplace_back(token);
		_vector.emplace_back(token);
	}
	catch (const std::exception &e)
	{
		throw std::invalid_argument("Error invalid input");
	}
}

void PmergeMe::SeqBeforeSorting(const PmergeMe &object)
{
	std::cout << "\nBefore: ";
	for (int value : object._deque)
	{
		std::cout << "[" << value << "] ";
	}
	std::cout << std::endl;
}



bool PmergeMe::isSorted(const PmergeMe &object)
{
	for (size_t value = 0; value < object._deque.size() - 1; value++)
	{

		if (_deque[value] > _deque[value + 1])
			return false;
	}
	return true;
}

void PmergeMe::printTimesDeque(clock_t startTime, clock_t endTime , std::deque<int> object)
{
	double timeDeque = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	//double intpart;
	//double fractpart = modf(timeDeque, &intpart);
	//fractpart = roundf(fractpart * 100000.0) / 100000.0;
	//double result = intpart + fractpart;
	std::cout<<std::fixed<<std::setprecision(5)

	<< "\nTime to process a range of " << object.size()
			  << " elements with std::deque : "
			  << timeDeque << " us" << std::endl;
}
void PmergeMe::printTimesVector(clock_t startTime, clock_t endTime , std::vector<int> object)
{
	double timeDeque = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
	//double intpart;
	//double fractpart = modf(timeDeque, &intpart);
	//fractpart = roundf(fractpart * 100000.0) / 100000.0;
	//double result = intpart + fractpart;
	std::cout<<std::fixed<<std::setprecision(5)

	<< "Time to process a range of " << object.size()
			  << " elements with std::vector : "
			  <<  timeDeque << " us" << std::endl;
}

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


