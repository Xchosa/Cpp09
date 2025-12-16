/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:28 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/16 18:02:38 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "BitcoinExchange.hpp"



void readInputandPrintBitcoin(std::string inputFilePath, std::map<std::string,double> DbMap)
{
	std::ifstream BtcFile(inputFilePath);
    if(!BtcFile.is_open())
    {
        throw std::runtime_error ("file not readable");
    }
    
    std::string line;
    while(std::getline(BtcFile, line))
    {
        trim(line);
		if(line.empty())
			continue;
		if(line.find("date | value") == 0)
			continue;;
		std::cout << "Input file: " << line << std::endl;
        size_t found = line.find("|");
        if (found == std::string::npos)
        {
            std::cerr << " invalid line" << std::endl;
            continue;
        }
        std::string date = line.substr(0, found-1);
		//std::cout << "date: " << date << std::endl;
        if (convertDate(date) < 20090102 || convertDate(date) > 20251230)
        {
            std::cerr << "Error: Bad input ==>" << date << std::endl;
            continue;
            
        }
        
        //std::map<std::string, double>::const_iterator DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
		auto DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
        
		std::cout << "test" << std::endl;
		std::cout << "matching line in data Base:" << "[" << DbMapFoundDate->first  << " | " << DbMapFoundDate->second  << "]" << std::endl;
		//std::cout << "price: " << DbMapFoundDate->second << std::endl;
        //colorprint(DbMapFoundDate->first, GREEN);
        
        //double amount = convertAmount(line, found);
        //if(!amount)
        //    continue;
        //line.substr(found, line.end())
        
    }
    BtcFile.close();
}

double convertDate(const std::string &date)
{
	std::string stringDate = date;
	std::cout << "date converted before: " << stringDate << std::endl;
	
	auto newEnd = std::remove(stringDate.begin(), stringDate.end(), '-');
	stringDate.erase(newEnd, stringDate.end());
	

	// seperate function check 5 und 6 position <= 12
	// separate function 7 und 8 position <= 31 (if 1,3,5,7,8, 10, 12 -> 31 else 30) 
	std::cout << "date converted: " << stringDate << std::endl;
	try
	{
		double convertedDate = std::stod(stringDate);
		return convertedDate;
	}
	catch(const std::exception& e)
	{
		throw std::invalid_argument("invalid date conversion");
	}
	return 1;
};

// find all dates that are less then date
		// 2012-01-11
		// return rate with the highest date 
		// if no earlier date exist 
			// return error

std::map<std::string, double>::const_iterator FindRateForDate(const std::map<std::string, double >& DbMap, const std::string& date)
{
	if(DbMap.empty())
		return DbMap.end();
	auto it = DbMap.find(date);

	std::cout << "matching Date found:" << "[" << it->first  << " | " << it->second  << "]" << std::endl;

	//std::map<std::string, double>::const_iterator it = DbMap.find(date);

	if (it != DbMap.end())
	{
		colorprint(it->first, GREEN);
		return (it);
	}
	else 
	{
		double doubleDate  = convertDate(date);
		double closestDate = 20090102;
		std::map<std::string, double>::const_iterator iter2 = DbMap.end();
		for (auto iter = DbMap.begin(); iter != DbMap.end(); iter++ )
		{
			double MapDate = convertDate(iter->first);
			if(MapDate < doubleDate)
			{
				// 20120111 < 20120220
				double tmpDateDif = doubleDate - MapDate;
				double tmpDateDif2 = doubleDate - closestDate;
				if(tmpDateDif < tmpDateDif2)
				{
					closestDate = MapDate;
					iter2 = iter;
				}
			}
		}
		if (iter2 != DbMap.end())
			colorprint(iter2->first, GREEN);
		//return iter2->second;// 
		return(iter2);
	}
	
}