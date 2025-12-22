/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:50 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/22 10:05:28 by poverbec         ###   ########.fr       */
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

#include <stack>

bool checkValid(std::string number);
bool isoperator(std::string number);
bool isNotNegativ(std::string number);
void check_stack(std::stack<float> stack);
void addStack(std::string token, std::stack<float> &stack);
void checkSyntax(std::string token, std::stack<float> &stack, std::istringstream &NbrStream);

float RPN(std::string number);
