/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:34:22 by poverbec          #+#    #+#             */
/*   Updated: 2025/12/15 14:58:51 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"

void colorprint(const std::string &str, const std::string &color) {
  if (color == RED)
    std::cerr << colortxt("[Error]: ", RED) << str << std::endl;
  else if (color == GREEN)
    std::cout << colortxt("[Success]: ", GREEN) << str << std::endl;
  else
    std::cout << colortxt(str, color);
}

std::string colortxt(const std::string &str, const std::string &color) {
  return (color + str + RESET);
}

// Section marker
void section(const std::string &title) {
  std::cout << std::endl;
  colorprint("==================== ", ORANGE);
  colorprint(title, ITALIC);
  colorprint(" ====================\n", ORANGE);
}