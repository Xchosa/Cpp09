/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/18 12:15:54 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"




bool checkValid (std::string number )
{
	std::size_t invalidchar = number.find_first_not_of("1234567890+-*/ ");
	if(invalidchar != std::string::npos)
	{
		std::cout << "Error: " <<  number[invalidchar];
		std::cout << " at position " << invalidchar << '\n';
		return false;
	}
	return true;
}


int RPN(std::string number)
{
	std::deque<std::string> stack(number.size());
	
	if(size_t space = number.find_first_not_of(" ") != std::string::npos)
		number = number.substr(space, number.size() - space);
	for (auto i = 0; i < (int)number.size() ; i++)
	{
		if(std::to_string(number.at(i)) == " ")
			i++;
		stack.emplace_back(number.substr(i, 1));
	}
	for (std::string value : stack)
	{
		std::cout << value << std::endl;
	}
	return 0;
	//int nbr = std::stod(number.substr(i, 1));
}


void trim(std::string &str)
{
	size_t s1 =  str.find_first_not_of(" \t\r");
	if(s1 == std::string::npos)
	{
		str.clear();
		return;
	}
	size_t s2 = str.find_last_not_of(" \t\r");
	str = str.substr(s1, s2 - s1 + 1);
}
