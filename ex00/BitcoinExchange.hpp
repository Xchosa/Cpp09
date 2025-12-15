/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/15 09:43:32 by poverbec         ###   ########.fr       */
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
		std::size_t found = line.find("|");
		if(found == std::string::npos)
		{
			std::cerr << "invalid line" << std::endl;
			continue;
		}
		std::string date = line.substr (0,found -1);
		std::string value = line.substr(found + 1);
		double valuedb = std::stod(value);
		// if (valuedb)
		
		
		DbMap.insert({date, valuedb});
		
	}
	return DbMap;
};

double FindRateForDate(const std::map<std::string, double >& DbMap, const std::string& date)
{
	//std::iterator *it;
	//for(interator map = it; it != it.end(); it++)
	//{
		
	//}
	std::iterator it = DbMap.find(date);
	
	//auto it = DbMap.find(date);
	if (it != DbMap.end())
	{
		return (*it);
	}
	else 
	{
		// find all dates that are less then date
		// 2012-01-11
		// return rate with the highest date 
		// if no earlier date exist 
			// return error

		
	}
	
}


