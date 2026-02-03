/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:04:01 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/03 15:59:22 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template <typename _Tp >
class MutantStack : public std::stack<_Tp>
{
public:
    typedef typename std::stack<_Tp>::container_type::iterator iterator;

    MutantStack( void );
    MutantStack(MutantStack &src);
    MutantStack &operator=(MutantStack &rhs);
    ~MutantStack();

    iterator begin();
    iterator end();

private:
};

template <typename _Tp>
std::ostream& operator<<(std::ostream& o, const MutantStack<_Tp>& rhs);

#endif //MUTANTSTACK_HPP
