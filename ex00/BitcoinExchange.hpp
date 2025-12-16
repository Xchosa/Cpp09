/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/16 11:52:00 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "iostream"
#include "string"
#include "map"
#include "utility" 

#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <exception>

#include "../color/color.hpp"



std::string create_inputFilePath(char **argv);

void trim(std::string &str);

std::map<std::string,double> loadDataBase(std::string dbPath);
void readInputandPrintBitcoin(std::string inputFilePath, std::map<std::string,double> DbMap);
double convertDate(const std::string &date);
std::map<std::string, double>::const_iterator FindRateForDate(const std::map<std::string, double >& DbMap, const std::string& date);


