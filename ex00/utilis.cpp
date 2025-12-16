/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:02:16 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/16 18:15:13 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

#include "BitcoinExchange.hpp"

void testToFile(std::map<std::string,double> DbMap)
{
	std::ofstream myfile;
	myfile.open("DataBase/output.txt");
	if (!myfile.is_open())
    {
        std::cerr << "could not open output file\n";
        return;
    }
	for (const auto &content : DbMap)
	{
		myfile <<  content.first << "|" << content.second << '\n';
	}
	myfile.close();
};

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
		
		std::string date = line.substr (0,comma -1);
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
	else
	{
		auto last = std::prev(DbMap.end()); // pointer to last iterator
		std::cout << "DbMap filled last line :" << "[" << last->first  << " | " << last->second  << "]" << std::endl;
	}
	testToFile(DbMap);
	
	return DbMap;
};


