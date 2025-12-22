/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:46:49 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/22 13:32:20 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "PmergeMe.hpp"

/*
$>
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"


*/

// container choice stack / or deque
// lifo / filo prinzip

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "more than 2 arguments needed \n usage: ./PmergeMe x y z " << std::endl;
		return 1;
	}
	int i = 0;
	try
	{
		PmergeMe PmM;
		while (!argv[i])
		{
			std::string number = argv[i];
			//if (checkValid(number) == false)
			//	return 0;
			PmM.filldeque(number);
			
			// add to deque stack
		} 
		PmM.SeqBeforeSorting(PmM);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
