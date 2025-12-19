/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/19 17:05:26 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include "stack"
#include "sstream"
#include "exception"

void check_stack(std::stack<float> stack)
{
	std::stack<float> stackb(stack);
	std::cout << "Stack controll" << std::endl;
	while(!stackb.empty())
	{
		std::cout << "[" << stackb.top() << "]" << '\n';
		stackb.pop();
	}
}


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

	// std::cout << " check: [ hallo]" << '\n';
	float nbr = std::stof(token);

	stack.push(nbr);
	check_stack(stack);
}

void operation(std::stack<float> &stack, std::string token)
{

	if (stack.size() > 2)
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

void operation3(std::stack<float> &stack, std::string token)
{

	if (stack.size() > 3)
		throw std::invalid_argument("Error not 2 numbers");

	float a = stack.top();
	stack.pop();
	float b = stack.top();
	stack.pop();
	float c = stack.top();
	stack.pop();
	float result;

	switch (token[0])
	{
	case ('+'):
		result = b + c;
		break;
	case ('-'):
		result = b - c;
		break;
	case ('*'):
		result = b * c;
		break;
	case ('/'):
		result = b / c;
		break;

	default:
		throw std::invalid_argument("Error invalid input");
	}
	stack.push(a);
	stack.push(result);
}

float RPN(std::string number)
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
				if(stack.size() == 2)
					operation(stack, token);
				if(stack.size() == 3)
					operation3(stack, token);
					
			}
			catch (const std::exception &e)
			{
				std::cerr << e.what() << '\n';
				return 1;
			}
		}
		if (!stack.empty())
		{
			std::cout << "Stack Check in the loop" << std::endl;
			std::cout << "[" << stack.top() << "]" << '\n';
			// if (stack.size() == 1)
			//	return stack.top();
		}
	}

	std::cout << "Stack Check" << std::endl;


	if (stack.empty())
		return 0;

	float result = stack.top();
	std::cout << "[" << stack.top() << "]" << '\n';
	return result;
}


/*

To calculate Reverse Polish Notation (RPN),
 read the expression left-to-right,
 pushing numbers onto a stack, and when you hit an operator,
 pop the top two numbers,
  perform the operation (second-popped operator first),
   and push the result back;
 the final answer is the last number left on the stack. */
