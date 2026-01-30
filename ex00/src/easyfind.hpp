
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobe <kobe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:38:11 by kobe              #+#    #+#             */
/*   Updated: 2026/01/29 16:40:12 by kobe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <stdlib.h> //strtod
#include <cmath>    //isnan
#include <limits>
#include <algorithm>

class NotFindException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "!!!NOT FIND SORRY!!!";
        }
    };

template <typename T>
int easyfind(T &cont, int &toFind)
{
    typename T::const_iterator it;
    it = std::find(cont.begin(), cont.end(), toFind);
    if (it == cont.end())
        throw NotFindException();
    return (*it);
}

#endif // EASYFIND_HPP
