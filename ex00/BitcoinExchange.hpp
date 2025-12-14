/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/13 14:19:18 by poverbec         ###   ########.fr       */
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


//template <typename T>
//std::pair <int, std::string > loadedDataBase;
//{
	
//}
void trim(std::string str)
{
	//str.erase(0, str.find_first_not_of(" "));
	//str.erase(str.find_last_not_of(" ") + 1);

	size_t s1 =  str.find_first_not_of(" ");
	if(!std::string::npos)
		return;
	size_t s2 = str.find_last_not_of(" ");
	str = str.substr(s1, s2 - s1 + 1);
}

std::map<std::string,double> loadDataBase(std::string dbPath)
{
	std::map < std::string, double> DbMap;
	std::ifstream BtcFile(dbPath.c_str());
	if(!BtcFile.is_open())
	{
		std::cerr << "could not open DataBase" << std::endl;
		return DbMap;
	}
	std::string line;
    while(std::getline(BtcFile, line))
	{
		trim(line);
		if(line.empty())
			continue;
		if(line.find("date | value", 0))
			continue;;
		std::string data = line.substr()
	}
	

	return DbMap;
}

double storeFindRateForDate(const std::map<std::string, double >& DbPath, const std::string& date)
{
	auto it = d

	std::string line;
    while(std::getline(BtcFile, line))
	{
		trim(line);
		if(line.empty())
			continue;
		if(line.find("date | value", 0))
			continue;;
		std::string data = line.substr()
}

