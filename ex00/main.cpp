/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:26:46 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/10 10:48:34 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <string>



char *writeFile(BtcFile, line)
{
    std::ofstream outfile("formatedData.csv");
    if(!outfile.is_open()) {
		std::cerr << "Error: file not writable" << std::endl;
        BtcFile.close();
    	exit (1);
    }
}


int main(int argc, char** argv)
{

	if(argc != 2)
	{
		std::cerr << "too many arguments given \n Usage: ./btc <input_file>" << std::endl;
        return 1;
	}
	
    std::ifstream BtcFile(argv[1]);
    if(!BtcFile.is_open())
    {
        std::cerr << "file not readable" << std::endl;
        return 1;
    }
    std::string line;
    while(std::getline(BtcFile, line))
    {
        std::outfile << writeFile(BtcFile, line);
    }
    BtcFile.close();
    return 0;
}