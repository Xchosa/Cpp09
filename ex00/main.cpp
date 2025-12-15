/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:26:46 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/15 16:38:02 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <string>



std::string create_inputFilePath(char **argv)
{
    std::string s1 = "DataBase/";
    std::string s2 = argv[1];
    return (s1 + s2);
    
}


int main(int argc, char** argv)
{

	if(argc != 2)
	{
		std::cerr << "too many arguments given \n Usage: ./btc <input_file>" << std::endl;
        return 1;
	}
	
    std::map<std::string,double> DbMap = loadDataBase("DataBase/data.csv");   
    std::string inputFilePath =create_inputFilePath(argv[1]);
    
    
    std::ifstream BtcFile(inputFilePath);
    if(!BtcFile.is_open())
    {
        std::cerr << "file not readable" << std::endl;
        return 1;
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
        
        std::map<std::string, double>::DbMapFoundDate =  FindRateForDate(DbMap, date); // price of csv file
        
        double amount = convertAmount(line, found);
        if(!amount)
            continue;
        line.substr(found, line.end())
        
    }
    BtcFile.close();
    return 0;
}

double convertAmount(std::string line, size_t found)
{

    std::string amoundStr = line.substr(found, line.end(), line.size());
    std::atol(amoundStr)
    {
        std::cerr << "Error: not a positiv numbe." << std::endl;
    }
    // error for negative number
    // error for to big number, 
}
/*
2022-03-29
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number
*/