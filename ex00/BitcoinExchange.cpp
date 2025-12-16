/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:28 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/16 12:29:22 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "BitcoinExchange.hpp"


	


std::string create_inputFilePath(char **argv)
{
    std::string s1 = "DataBase/";
    std::string s2 = argv[1];
    return (s1 + s2);
    
}

void trim(std::string &str)
{
	size_t s1 =  str.find_first_not_of(" \t\r");
	if(s1 == std::string::npos)
	{
		str.clear();
		return;
	}
	size_t s2 = str.find_last_not_of(" \t\r");
	str = str.substr(s1, s2 - s1 + 1);
}

std::map<std::string,double> loadDataBase(std::string dbPath)
{
	std::map < std::string, double> DbMap;
	std::cout << dbPath <<std::endl;
	std::ifstream BtcFile(dbPath.c_str());
	if(!BtcFile.is_open())
	{
		throw std::runtime_error ("could not open DataBase");
	}
	std::string line;
    while(std::getline(BtcFile, line))
	{
		trim(line);
		if(line.empty())
			continue;
		if(line.find("date | value") != std::string::npos)
			continue;;
		std::size_t found = line.find("|");
		if(found != std::string::npos)
		{
			std::cerr << "invalid line" << std::endl;
			continue;
		}
		//std::cout << "Print trimmed line before printing " << line << std::endl;
		
		std::string date = line.substr (0,found -1);
		std::cout << date << std::endl;
		std::string value = line.substr(found + 1);
		std::cout << value << std::endl;
		try
		{
			double valuedb = std::stod(value);
			DbMap.insert({date, valuedb});
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "DbMap filled: " << std::endl;
	//std::cout << "DbMap filled: " << DbMap.end()->first << std::endl;
	return DbMap;
};


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
		if(line.find("date | value", 0))
			continue;;
        size_t found = line.find("|");
        if (found == std::string::npos)
        {
            std::cerr << " invalid line" << std::endl;
            continue;
        }
        std::string date = line.substr(0, found -1);
        if (convertDate(date) < 20090102 || convertDate(date) > 20220330)
        {
            std::cerr << "Error: Bad input ==>" << date << std::endl;
            continue;
            
        }
        
        std::map<std::string, double>::const_iterator DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
        
        colorprint(DbMapFoundDate->first, GREEN);
        
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

	auto newEnd = std::remove(stringDate.begin(), stringDate.end(), '-');
	stringDate.erase(newEnd, stringDate.end());
	

	// seperate function check 5 und 6 position <= 12
	// separate function 7 und 8 position <= 31 (if 1,3,5,7,8, 10, 12 -> 31 else 30) 
	std::cout << stringDate << std::endl;

	return(std::stod(stringDate));
};

// find all dates that are less then date
		// 2012-01-11
		// return rate with the highest date 
		// if no earlier date exist 
			// return error

std::map<std::string, double>::const_iterator FindRateForDate(const std::map<std::string, double >& DbMap, const std::string& date)
{
	
	std::map<std::string, double>::const_iterator it = DbMap.find(date);
	//auto it = DbMap.find(date);
		
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
		for (std::map<std::string, double>::const_iterator iter; iter != DbMap.end(); iter++ )
		{
			
			double MapDate = convertDate(it->first);
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