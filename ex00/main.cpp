/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:26:46 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/16 12:10:28 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <string>

#include "../color/color.hpp"




int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr << "too few arguments given \n Usage: ./btc <input_file>" << std::endl;
        return 1;
	}
	try
    {
        std::map<std::string,double> DbMap = loadDataBase("DataBase/data.csv");
        std::string inputFilePath =create_inputFilePath(argv);
        std::cout << "Filepath "<< inputFilePath << std::endl;
        readInputandPrintBitcoin(inputFilePath, DbMap);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

//double convertAmount(std::string line, size_t found)
//{

//    std::string amoundStr = line.substr(found, line.end(), (line.size() - found));
   
//    double amount;
//    amount = std::atol(amoundStr);
//    if(!std::atol(amoundStr))
//    {
//        std::cerr << "Error: not a positiv number." << std::endl;
//    }
//    amo
//    // error for negative number
//    // error for to big number, 
//}
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