/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/22 10:57:51 by poverbec         ###   ########.fr       */
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
	if (number[0] == '-' && number.size() <= 2)
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


void checkSyntax(std::string token, std::stack<float> &stack, std::istringstream &NbrStream)
{
	std::stack<float> stackb(stack);
	std::cout << "Stack controll syntax" << std::endl;
	int digitsInStack = 0;
	int operatorsInStack = 0;
	while(!stackb.empty())
	{
		std::cout << "[" << stackb.top() << "]" << '\n';
		if(isoperator(std::to_string(stackb.top())))
			operatorsInStack++;
		if(isdigit(token[0]) && isNotNegativ(token))
			digitsInStack++;
		stackb.pop();
	}
	if(digitsInStack == 2 && operatorsInStack == 0 && (NbrStream.peek() == EOF ))
		throw std::invalid_argument("Syntax Error, operator missing");
	//std::cout << "digits: " << digitsInStack << " | operatorsInStack: " << operatorsInStack << "tokensize: " << token.empty() << std::endl;
}



void addStack(std::string token, std::stack<float> &stack)
{

	if(stack.size() == 3)
		throw std::invalid_argument("Error: invalid syntax ");
	float nbr = std::stof(token);
	

	stack.push(nbr);
	//std::cout << "Number added"  << std::endl;
	//check_stack(stack);
}

void operation(std::stack<float> &stack, std::string token)
{

	if (stack.size() > 2)
		throw std::invalid_argument("Error not 2 numbers");
	//check_stack(stack);
	float b = stack.top();
	stack.pop();
	float a = stack.top();
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
	//check_stack(stack);
	float c = stack.top(); // b 
	stack.pop();
	float b = stack.top(); // a
	stack.pop();
	float a = stack.top();
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
	stack.push(c);
}

float RPN(std::string number)
{
	std::stack<float> stack;
	std::istringstream ss(number);

	std::string token;
	//std::cout << "size of string: " << std::to_string(number.size()) << std::endl;

	int i = 0;
	while (ss >> token)
	{
		//std::cout << "round: " << i <<" [" << token << "]" << std::endl;
		//checkSyntax(token,stack, ss);
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
		else if(isoperator(token))
		{
			try
			{
				//std::cout << "stack size: " << stack.size() << std::endl;
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
		i++;
	}
	if(stack.size() == 2)
		throw std::invalid_argument("Syntax Error, operator missing");
	//std::cout << "Stack Check" << std::endl;


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
