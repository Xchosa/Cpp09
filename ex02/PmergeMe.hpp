/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:01:05 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/22 13:30:24 by poverbec         ###   ########.fr       */
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

	void filldeque(std::string number);
	void SeqBeforeSorting(const PmergeMe &object);
};