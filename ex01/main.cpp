/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:46:49 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/18 12:06:25 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "RPN.hpp"

/*
$> 
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42$> 
./RPN "7 7 * 7 -"
42$> 
./RPN "1 2 * 2 / 2 * 2 4 - +"
0$> 
./RPN "(1 + 1)
"Error$>

only int numbers no brackets

*/

// container choice stack / or deque 
// lifo / filo prinzip



int main(int argc, char **argv)
{
	if(argc != 2)
		std::cerr << "only one argument allowed \n usage: ./RPN \"x y + " << std::endl; 
	std::string number = argv[1];
	if (checkValid (number) == false)
		return 0;
	try
	{
		int result = RPN(number);
		std::cout << std::to_string(result) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
		
	return 0;
}


