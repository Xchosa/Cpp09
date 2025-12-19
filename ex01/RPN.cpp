/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/19 09:45:43 by poverbec         ###   ########.fr       */
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
	std::deque<std::string> stack;
	
	std::cout << "size of string: " <<std::to_string(number.size()) << std::endl;
	//if(size_t space = number.find_first_not_of(" ") != std::string::npos)
	//	number = number.substr(space, number.size() - space);
	std::cout << "positon 2: "<< std::to_string(number.at(2)) << std::endl;
	
	for (auto i = 0; i < (int)number.size() ; i++)
	{
		if(number.at(i) == ' ')
			continue;
	std::cout << "[" <<number.substr(i,1)<< "]"<< std::endl;
	stack.emplace_back(number.substr(i, 1));
	}

	std::cout << "Stack Check"  << std::endl;
	for ( auto &value : stack)
	{
		std::cout << "[" << value << "]"<< std::endl;
	}
	
	for (auto i  = stack.begin() ; i < stack.end(); i++ )
	{
		
		if(std::stoi(stack[i]) )
		
		if (i != stack.find("1234567890"))
		{
			int number1 = stack[i];
			i++;
		}
		if (i != stack.find("1234567890"))
		{
			int number2 = stack[i];
			i++;
		}
		if (i != stack.find("+-*/"));
			int number2 = stack[i];
		i++;
		if(stack[i] != '+-*/')
			t
		int result = xy
		stack.emplace_front(result);
		
	}
	// iterate find operator 
	return 0;
	//int nbr = std::stod(number.substr(i, 1));
}


/*

To calculate Reverse Polish Notation (RPN),
 read the expression left-to-right, 
 pushing numbers onto a stack, and when you hit an operator, 
 pop the top two numbers,
  perform the operation (second-popped operator first),
   and push the result back;
 the final answer is the last number left on the stack. */
