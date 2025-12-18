/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 18:02:16 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/18 10:55:35 by poverbec         ###   ########.fr       */
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
	for (auto &content : DbMap)
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


bool Schaltjahr(int dataYY, int dataMM, int dataDD)
{
	if (dataMM < 1 || dataMM > 12 || dataDD < 1 || dataDD > 31)
		return false;
	if(dataMM == 4 || dataMM == 6 || dataMM == 9 || dataMM == 11)
	{
		if(dataDD > 30)
			return false;
	}
	else if(dataMM == 2)
    {
        if( (dataYY % 100 == 0 ) && ( dataYY % 400 == 0))
        {
            if(dataDD > 29)
                return false;
        }
        else if ((dataYY % 4 == 0 ) && (dataYY % 100 != 0 ))
        {
            if(dataDD > 29)
                return false;
        }
        else if (dataDD > 28)
        {
            return false;
        }
	}
	return true;
}



bool checkValidDate(std::string data)
{
	int dataDb = convertDate(data);
	if (dataDb < 20090102) /// implent boool
    {
        std::cerr << "Error: Bad input: invalid year ==> " << data << std::endl;
		return false;
    }
	int dataMM = convertDate(data.substr(5,2));
	if (dataMM > 12)
	{
        std::cerr << "Error: Bad input: invalid month ==> " << data << std::endl;
		return false;
    }
	int dataDD = convertDate(data.substr(8,2));
	if(dataDD > 31)
	{
		std::cerr << "Error: Bad input: invaild day ==> " << data << std::endl;
		return false;
    }
	int dataYY = convertDate(data.substr(0,4));
	if (Schaltjahr(dataYY, dataMM, dataDD) == false)
	{
		std::cerr << "Error: Bad input: invaild day ==> " << data << std::endl;
		return false;
	}
	return true;
};

