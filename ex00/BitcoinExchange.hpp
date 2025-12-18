/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/18 10:10:01 by poverbec         ###   ########.fr       */
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


// utilis
std::string create_inputFilePath(char **argv);
void trim(std::string &str);
double convertDate(const std::string &date);
void testToFile(std::map<std::string,double> DbMap);
bool checkValidDate(std::string data);
bool Schaltjahr(int dataYY, int dataMM, int dataDD);


// Bitcoin Exchange
std::map<std::string,double> loadDataBase(std::string dbPath);
void readInputandPrintBitcoin(std::string inputFilePath, std::map<std::string,double> DbMap);
double convertDate(const std::string &date);
std::map<std::string, double>::const_iterator FindRateForDate(const std::map<std::string, double >& DbMap, const std::string& date);


