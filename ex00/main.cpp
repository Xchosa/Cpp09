/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:26:46 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/13 13:39:16 by poverbec         ###   ########.fr       */
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
	loadDataBase("DataBase/data.csv");
    // load database DataBase/data.csv in container
    // load input.txt file --> argv[1] verarbeite zeile 
    // fuer zeile diesen input und print in console
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
        
        
    }
    BtcFile.close();
    return 0;
}