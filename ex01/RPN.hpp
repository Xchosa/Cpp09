/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:11:50 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/19 16:23:13 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include <deque>

bool checkValid (std::string number );

float RPN(std::string number);


