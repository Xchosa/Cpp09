/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:26:46 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/08 16:51:22 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"



int main()
{
    std::vector<int> container = { 10, 30, 32, 5, -4 , 100};
   
    int needle = 5;
    std::cout << "did u find the needle? " << *easyfind(container, needle) << std::endl;

    
    return 0;
}