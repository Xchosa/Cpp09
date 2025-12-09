/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:45:38 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/08 17:20:07 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>


template <typename T>
typename T::iterator easyfind(T& container, int needle)
{
	// find it manual
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == needle)
		{
			std::cout << "Found with own easyfind"<< std::endl;
			return it;
		}
	}
	throw std::runtime_error("Element not found");
	
	//auto found = std::find(container.begin(), container.end(), needle);
	//if (found != container.end())
	//{
	//	std::cout << "Found with find"<< std::endl;
	//	return  found;
	//}
	//throw std::runtime_error("Element not found");

}
	

