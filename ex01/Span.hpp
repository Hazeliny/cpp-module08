/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:33:41 by linyao            #+#    #+#             */
/*   Updated: 2025/02/09 22:13:05 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <ctime>

class Span
{
    private:
        long unsigned int   _n;
        std::vector<int>    _vec;
    public:
        Span();
        Span(long unsigned int n);
        Span(Span const &src);
        Span &operator=(Span const &src);
        ~Span();

        long unsigned int getN();

        void addNumber(int number);
        void addNumberOnce(long unsigned int nElements, time_t seed);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class AlreadyFullException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("The vector is already full!");
                }
            
        };
        class EmptyVectorEception : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("The vector is empty!");
                }
        };
        class OnlyOneException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("The vector has only one element!");
                }
        };
};

template <typename T>
void print(T &container)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
