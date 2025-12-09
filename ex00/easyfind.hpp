/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:45:45 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/08 16:55:25 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "iostream"
#include "string"


template <typename T>
typename T::iterator easyfind(T& container, int needle);





#include "easyfind.tpp"