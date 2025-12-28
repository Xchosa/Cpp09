/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:46:49 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/28 20:25:29 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>
#include <cmath>
#include <unistd.h>

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
	int i = 1;
	clock_t startTime;
	clock_t endTime;
	try
	{
		PmergeMe PmM;
		while (i < argc)
		{
			std::string number = argv[i];
			//if (checkValid(number) == false)
			//	return 0;
			PmM.fillDequeVector(number);
			i++;
			
			// add to deque stack
		} 
		PmM.SeqBeforeSorting(PmM);
		startTime = clock();
		sleep(2);
		PmM.SortingDeque(PmM);
		endTime = clock();
		PmM.printTimesDeque(startTime, endTime, PmM);

		startTime = clock();
		PmM.SortingVector(PmM);
		endTime = clock();
		PmM.printTimesVector(startTime, endTime, PmM);
		
		
		
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}


	
