/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/19 14:53:42 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include "stack"
#include "sstream"
#include "exception"

bool checkValid(std::string number)
{
	std::size_t invalidchar = number.find_first_not_of("1234567890+-*/ ");
	if (invalidchar != std::string::npos)
	{
		std::cout << "Error: " << number[invalidchar];
		std::cout << " at position " << invalidchar << '\n';
		return false;
	}
	return true;
}

bool isNotNegativ(std::string number)
{
	if (number[0] == '-' && number.size() >= 2)
		throw std::invalid_argument("Error: not negativ");

	return true;
}

bool isoperator(std::string number)
{
	if (number == "+")
		return true;
	if (number == "-")
		return true;
	if (number == "*")
		return true;
	if (number == "/")
		return true;
	return false;
}

void addStack(std::string token, std::stack<float> &stack)
{

	std::cout << " check: [ hallo]" << '\n';
	float nbr = std::stof(token);

	stack.push(nbr);
	std::cout << " check: [" << stack.top() << "]" << '\n';
}

void operation(std::stack<float> &stack, std::string token)
{

	if (stack.size() != 2)
		throw std::invalid_argument("Error not 2 numbers");

	float a = stack.top();
	stack.pop();
	float b = stack.top();
	stack.pop();
	float result;

	switch (token[0])
	{
	case ('+'):
		result = a + b;
		break;
	case ('-'):
		result = a - b;
		break;
	case ('*'):
		result = a * b;
		break;
	case ('/'):
		result = a / b;
		break;

	default:
		throw std::invalid_argument("Error invalid input");
	}
	stack.push(result);
}

int RPN(std::string number)
{
	std::stack<float> stack;
	std::istringstream ss(number);
	
	std::string token;
	std::cout << "size of string: " << std::to_string(number.size()) << std::endl;

	while (ss >> token)
	{
		std::cout << "[" << token << "]" << std::endl;

		if (isdigit(token[0]) && isNotNegativ(token))
		{
			std::cout << "Stack Check 2" << std::endl;
			try
			{
				addStack(token, stack);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				return 1;
			}
		}
		if (isoperator(token))
		{
			try
			{
				operation(stack, token);
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				return 1;
			}
		}
		if (!stack.empty())
		{
			std::cout << "Stack Check" << std::endl;
			std::cout << "[" << stack.top() << "]" << '\n';
		}
	}

	std::cout << "Stack Check" << std::endl;

	std::stack<float> stackb(stack);

	while (!stackb.empty())
	{
		std::cout << "[" << stackb.top() << "]" << '\n';
		stackb.pop();
	}

	return 0;
}

/*

To calculate Reverse Polish Notation (RPN),
 read the expression left-to-right,
 pushing numbers onto a stack, and when you hit an operator,
 pop the top two numbers,
  perform the operation (second-popped operator first),
   and push the result back;
 the final answer is the last number left on the stack. */
