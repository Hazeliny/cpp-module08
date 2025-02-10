/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:58:41 by linyao            #+#    #+#             */
/*   Updated: 2025/02/10 22:22:45 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {};
        MutantStack(MutantStack const &src) : std::stack<T>(src) {};
        MutantStack &operator=(MutantStack const &src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return *this;
        };
        virtual ~MutantStack() {};
        
        typedef typename std::stack<T>::container_type::iterator iterator; //the type of bottom container internally used in stack
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;//it is an iterator with const version

        //c is the bottom container of std::satck (protected member variable) (normally it is std::deque<T>)
        //here the iterator of bottom container is returned, so MutantStack has the iterator which std::stack hasn't
        iterator begin()
        {
            return std::stack<T>::c.begin();
        };
        iterator end()
        {
            return std::stack<T>::c.end();
        };
        const_iterator begin() const
        {
            return std::stack<T>::c.begin();    
        };
        const_iterator end() const
        {
            return std::stack<T>::c.end();
        };
};
