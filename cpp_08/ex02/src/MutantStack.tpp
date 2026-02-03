/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:08:27 by thodavid          #+#    #+#             */
/*   Updated: 2026/02/03 16:09:56 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename _Tp >
MutantStack<_Tp>::MutantStack( void ){ }

template <typename _Tp >
MutantStack<_Tp>::MutantStack( MutantStack &src ){ this->c = src.c; }

template <typename _Tp >
MutantStack<_Tp> &MutantStack<_Tp>::operator=(MutantStack &rhs){
    if (this == &rhs)
        return (*this);
}

template <typename _Tp >
MutantStack<_Tp>::~MutantStack(){ }

template <typename _Tp >
typename MutantStack<_Tp>::iterator MutantStack<_Tp>::begin(){ return (this->c.begin()); }

template <typename _Tp >
typename MutantStack<_Tp>::iterator MutantStack<_Tp>::end(){ return (this->c.end()); }

template <typename _Tp >
std::ostream& operator<<(std::ostream& o, MutantStack<_Tp> const & rhs){
    o << rhs.top();
}
