/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:30:34 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/02 14:04:33 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

//////////////////////////////////////////////////////////////////////////////
//
// main test : try 50k int
//
//
#include <ctime>

int main()
{
    try
    {
        Span s(500000);
        for(int i = 0; i < 500000; i++)
            s.addNumber(i * 3.42);
        s.printSpan();
        std::cout << '\n' << s.shortestSpan() << '\n';
        std::cout << s.longestSpan() << '\n';
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
}

//////////////////////////////////////////////////////////////////////////////
//
// main test : canonical + throw exception
// if there are no numbers stored, or only one, no span can be found. Thus, throw an exception
//

/*
int main()
{
    try
    {
        Span s = Span();
        Span cpy(s);
        Span cpy2;
        cpy2 = s;
        
        std::cout << cpy2.shortestSpan() << std::endl;
        std::cout << cpy2.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
}
*/



//////////////////////////////////////////////////////////////////////////////
//
// main test : throw exception
// tempt to add a new element if there are already N elements stored
//

/*
int main(){
    try{
        Span sp = Span(0);
        sp.addNumber(6);
        sp.addNumber(3);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return (1);
    }
    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////
//
// main test: subject
//  Should output:
//  $> ./ex01
//  2
//  14
//  $>
//
//

/*
int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
*/
