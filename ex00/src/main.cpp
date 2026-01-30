/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobe <kobe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:37:19 by kobe              #+#    #+#             */
/*   Updated: 2026/01/29 16:46:49 by kobe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int conv_to_int(double value);

int main()
{
    std::vector<int> v;
    int *toFind = new int;

    std::cout << "please enter some integer and enter 'OK' (one line one int)\n";
    while (1)
    {
        std::string prompt;
        std::cout << "> ";
        if (!std::getline(std::cin, prompt))
        {
            std::cout << "Err: getline()\n";
            return (1);
        }
        else
        {
            if (prompt == "OK")
                break;
            const char *pStr = prompt.c_str();
            char *pEnd;
            double value = std::strtod(pStr, &pEnd);
            v.push_back(conv_to_int(value));
        }
    }

    std::cout << "\n[DISPLAY VECTOR]\n{ ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "}\n\n";

    std::cout << "GREAT! now enter a number and press enter to find it\n";
    std::string prompt2;
    std::cout << "> ";
    if (!std::getline(std::cin, prompt2))
    {
        std::cout << "Err: getline()\n";
        return (1);
    }
    const char *pStr = prompt2.c_str();
    char *pEnd;
    double value = std::strtod(pStr, &pEnd);
    *toFind = conv_to_int(value);

    std::cout << "\nLETS GO!! the integer to find is: " << *toFind << '\n';

    std::cout << "Lets call easyfind()...\n\n"
    << "easyfind:: " << easyfind(v, *toFind) << '\n';

    delete toFind;
    return (0);
}

int conv_to_int(double value)
{
    if (!std::isfinite(value) || value > INT_MAX || value < INT_MIN)
    {
        std::cerr << "Not a integer get out";
        exit(1);
    }
    int x = static_cast<int>(value);
    return (x);
}