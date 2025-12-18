/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:08:28 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/18 10:52:06 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "BitcoinExchange.hpp"

std::map<std::string,double> loadDataBase(std::string dbPath)
{
	std::map < std::string, double> DbMap;
	//std::cout << dbPath <<std::endl;
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
		if(line.find("date") == 0)
			continue;;
		std::size_t comma = line.find(",");
		if(comma == std::string::npos)
		{
			std::cerr << "invalid line" << std::endl;
			continue;
		}
		//std::cout << "Print trimmed line before printing " << line << std::endl;
		
		std::string date = line.substr (0,comma);
		//std::cout << date << std::endl;
		std::string value = line.substr(comma + 1);
		//std::cout << value << std::endl;
		try
		{
			double valuedb = std::stod(value);
			DbMap.insert({date, valuedb});
		}
		catch(const std::exception& e)
		{
			std::cerr << "stod: " << e.what() << " (line: " << line << ")" << '\n';
			continue;
		}
	}
	if (DbMap.empty())
		std::cout << "DbMap is empty"<< std::endl;
	//else
	//{
	//	auto last = DbMap.end(); // pointer to last iterator
	//	//std::cout << "DbMap filled last line :" << "[" << last->first  << " | " << last->second  << "]" << std::endl;
	//}
	testToFile(DbMap);
	
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
		if(line.find("date | value") == 0)
			continue;;
        size_t found = line.find("|");
        //if (found == std::string::npos)
        //{
        //    std::cerr << " invalid line" << std::endl;
        //    continue;
        //}
        std::string date = line.substr(0, found-1);
		if(checkValidDate(date) == false)
        	continue;
		auto DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
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
		std::cout << DbMapFoundDate->first << " =>" << amount_input << " = " <<  value << std::endl;
    }
    BtcFile.close();
}

double convertDate(const std::string &date)
{
	std::string stringDate = date;
	auto newEnd = std::remove(stringDate.begin(), stringDate.end(), '-');
	stringDate.erase(newEnd, stringDate.end());
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

std::map<std::string, double>::const_iterator FindRateForDate(const std::map<std::string, double >& DbMap, const std::string& date)
{
	//std::cout << "DEBUG: FindRateForDate called with date: " << date << std::endl;
	if(DbMap.empty())
		throw std::out_of_range("Error: database is empty");
	auto it = DbMap.find(date); // 2011-01-03 != 2011-01-3 -> schneidet die ab im der data base -> wird nicht richtig eingelesen. 
	if (it != DbMap.end())
	{
		//std::cout << "matching Date found:" << "[" << it->first  << " | " << it->second  << "]" << std::endl;
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

			//std::cout << "matching Date found (closest):" << "[" << iter2->first  << " | " << iter2->second  << "]" << std::endl;
			//colorprint(iter2->first, GREEN);
		}
		//return iter2->second;// 
		//std::cout << "DEBUG: iter2 return value: " << iter2->first << std::endl;
		//std::cout << "DEBUG: After convertDate: " << std::to_string(iter2->second)<< std::endl;
		return(iter2);
	}
	
}