/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/22 18:31:11 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include "sstream"
#include "exception"

PmergeMe::PmergeMe() : _deque(0)
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
	return(*this);
}

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
void PmergeMe::filldeque(std::string number)
{

	int token;
	try
	{
		token = stoi(number);
		_deque.emplace_back(token);
	}
	catch(const std::invalid_argument& e)
	{
		throw std::invalid_argument("Error invalid input");
	}
	
}

void PmergeMe::SeqBeforeSorting(const PmergeMe &object)
{
	for (int value : object._deque)
	{
		std::cout << "[" << value << "]" << std::endl;
	}
	
	std::deque<float> stackb(stack);
	std::cout << "Stack controll" << std::endl;
	while(!stackb.empty())
	{
		std::cout << "[" << stackb.top() << "]" << '\n';
		stackb.pop();
	}
}
};