/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:34:08 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/05 16:34:10 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>

// Define colours
const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string BLUE = "\033[1;34m";
const std::string ORANGE = "\033[38;5;208m";
const std::string RESET = "\033[0m";
const std::string ITALIC = "\033[3m";

void colorprint(const std::string &str, const std::string &color);
std::string colortxt(const std::string &str, const std::string &color);
void section(const std::string &title);
