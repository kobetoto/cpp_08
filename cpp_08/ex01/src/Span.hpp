/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:38:38 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/02 13:22:15 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <deque>
#include <climits>
#include <exception>

class Span
{
public:
    Span(void);
    Span(unsigned int N);
    Span(Span const &src);
    Span &operator=(Span const &rightHandSide);
    ~Span();

    void addNumber(int num);
    int shortestSpan(void) const;
    int longestSpan(void) const;
    void printSpan();

    class TooManyElement : public std::exception
    {
        public: const char *what() const throw(){
            return ("Err max elements reach");
        }
    };

    class NotEnoughElement : public std::exception
    {
        public: const char *what() const throw(){
            return ("Not Enough Element");
        }
    };

private:
    unsigned int _max;
    std::deque<int> _span;
};
