/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:26:03 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/02 13:34:39 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* CTOR + DTOR */
Span::Span(void) : _max(0), _span(std::deque<int>(0)) {}
Span::Span(unsigned int N) : _max(N), _span(std::deque<int>()) {}
Span::Span(Span const &src) : _max(src._max), _span(src._span) {}
Span &Span::operator=(Span const &rightHandSide)
{
    if (this == &rightHandSide)
        return (*this);
    _span = rightHandSide._span;
    _max = rightHandSide._max;
    return *this;
}
Span::~Span() {}

/* f() MEMBER */
void Span::addNumber(int num)
{
    if (_span.size() >= _max)
        throw TooManyElement();
    _span.push_front(num);
}

int Span::longestSpan(void) const { 
    if (_span.size() < 2)
        throw NotEnoughElement();
    std::pair<std::deque<int>::const_iterator, std::deque<int>::const_iterator> min_max;

    min_max.first = std::min_element(_span.begin(), _span.end());
    min_max.second = std::max_element(_span.begin(), _span.end());

    return (*min_max.second - *min_max.first);
}

int Span::shortestSpan(void) const {
    if (_span.size() < 2)
        throw NotEnoughElement();

    std::deque<int> tmp = _span;
    std::sort(tmp.begin(), tmp.end());

    std::deque<int>::size_type i = 2;
    long long minSpan = static_cast<long long>(tmp[1]) - static_cast<long long>(tmp[0]);
    
    while (i < tmp.size()){
        long long temp = static_cast<long long>(tmp[i]) - static_cast<long long>(tmp[i-1]);
        if (temp < minSpan)
            minSpan = temp;
        ++i;
    }
    if (minSpan > INT_MAX)
        throw std::runtime_error("Span Overflow");
    return (static_cast<int>(minSpan));
}

void Span::printSpan()
{
    for (std::deque<int>::iterator it = _span.begin(); it != _span.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
}
