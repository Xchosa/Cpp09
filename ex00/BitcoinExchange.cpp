/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:28 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/17 19:05:58 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "BitcoinExchange.hpp"


bool checkValidDate(std::string date)
{
	// schalt jahr 
	//convertDate(date) < 20090102
	
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
		if(line.find("date | value") == 0)
			continue;;
		//std::cout << "Input file: " << line << std::endl;
        size_t found = line.find("|");
        //if (found == std::string::npos)
        //{
        //    std::cerr << " invalid line" << std::endl;
        //    continue;
        //}
        std::string date = line.substr(0, found-1);
		//std::cout << "date: " << date << std::endl;
        if (convertDate(date) < 20090102) /// implent boool
        {
            std::cerr << "Error: Bad input ==> " << date << std::endl;
            continue;
            
        }
        
        //std::map<std::string, double>::const_iterator DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
		auto DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
		
        
		//std::cout << "test" << std::endl;
		//std::cout << "matching line in data Base:" << "[" << DbMapFoundDate->first  << " | " << DbMapFoundDate->second  << "]" << std::endl;
		//std::cout << "price: " << DbMapFoundDate->second << std::endl;
        //colorprint(DbMapFoundDate->first, GREEN);
        
        double amountDB = DbMapFoundDate->second;
	
		
        std::string amount_input = line.substr(found + 1);
		trim(amount_input);
		if(amount_input.size() == 0)
		{
			std::cerr << "invalid line" << std::endl;
			 continue;
		}
		double amount_inputdb = std::stod(amount_input);

        if(amount_inputdb > __INT_MAX__ )
		{
			 std::cerr << "Error: Too big number " << std::endl;
			 continue;
		}
		else if(amount_inputdb < 0)
		{
			std::cerr << "Error: not a positive number. " << std::endl;
			continue;
		}
		double value = amountDB * amount_inputdb ;
;		std::cout << DbMapFoundDate->first << " =>" << amount_input << " = " <<  value << std::endl;
		



		

		// mulitplizieren 
        
    }
    BtcFile.close();
}

double convertDate(const std::string &date)
{
	std::string stringDate = date;
	//std::cout << "date converted before: " << stringDate << std::endl;
	
	auto newEnd = std::remove(stringDate.begin(), stringDate.end(), '-');
	stringDate.erase(newEnd, stringDate.end());
	

	// seperate function check 5 und 6 position <= 12
	// separate function 7 und 8 position <= 31 (if 1,3,5,7,8, 10, 12 -> 31 else 30) 
	//std::cout << "date converted: " << stringDate << std::endl;
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
	//std::cout << "DEBUG: FindRateForDate called with date: " << date << std::endl;
	if(DbMap.empty())
		throw std::out_of_range("Error: database is empty");
	auto it = DbMap.find(date); // 2011-01-03 != 2011-01-3 -> schneidet die ab im der data base -> wird nicht richtig eingelesen. 
	
	
	//std::map<std::string, double>::const_iterator it = DbMap.find(date);
	
	if (it != DbMap.end())
	{
		//std::cout << "matching Date found:" << "[" << it->first  << " | " << it->second  << "]" << std::endl;
		//colorprint(it->first, GREEN);
		return (it);
	}
	else 
	{
		double doubleDate  = convertDate(date);
		//std::cout << "DEBUG: After convertDate: " << std::to_string(doubleDate)<< std::endl;
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
		{
			//iter2 = std::prev(DbMap.end());
			//std::cout << 
			//std::cout << "matching Date found (closest):" << "[" << iter2->first  << " | " << iter2->second  << "]" << std::endl;
			
			//colorprint(iter2->first, GREEN);
		}
		//return iter2->second;// 
		//std::cout << "DEBUG: iter2 return value: " << iter2->first << std::endl;
		//std::cout << "DEBUG: After convertDate: " << std::to_string(iter2->second)<< std::endl;
		return(iter2);
	}
	
}