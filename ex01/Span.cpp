/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:50:46 by linyao            #+#    #+#             */
/*   Updated: 2025/02/09 22:04:34 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(10000), _vec()
{}
        
Span::Span(long unsigned int n) : _n(n), _vec()
{}
        
Span::Span(Span const &src)
{
    *this = src;
}
        
Span &Span::operator=(Span const &src)
{
    this->_n = src._n;
    this->_vec = src._vec;
    return (*this);
}
        
Span::~Span(){}

long unsigned int Span::getN()
{
    return this->_n;
}

void Span::addNumber(int number)
{
    if (this->_vec.size() == this->getN())
        throw (Span::AlreadyFullException());
    this->_vec.push_back(number);
}

void Span::addNumberOnce(long unsigned int nElements, time_t seed)
{
    srand(seed);
    for (size_t i = 0; i < nElements; i++)
    {
        try
        {
            addNumber(rand());
        }
        catch(Span::AlreadyFullException& e)
        {
            std::cerr << e.what() << '\n';
        }   
    }
}
        
unsigned int Span::shortestSpan() const
{
    if (!this->_vec.size())
        throw Span::EmptyVectorEception();
    else if (this->_vec.size() == 1)
        throw Span::OnlyOneException();
    std::vector<int> cp(this->_vec);
    std::sort(cp.begin(), cp.end());
    unsigned int min = std::numeric_limits<unsigned int>::max();
    std::vector<int>::iterator it = cp.begin();
    std::vector<int>::iterator itNext = cp.begin() + 1;
    while (itNext != cp.end())
    {
        if ((unsigned int)(*itNext - *it) < min)
            min = *itNext - *it;
        it++;
        itNext++;
    }
    return (min);
}
        
unsigned int Span::longestSpan() const
{
    if (!this->_vec.size())
        throw Span::EmptyVectorEception();
    else if (this->_vec.size() == 1)
        throw Span::OnlyOneException();
    std::vector<int> cp(this->_vec);
    int min, max;
    std::sort(cp.rbegin(), cp.rend());
    max = *cp.begin();
    std::sort(cp.begin(), cp.end());
    min = *cp.begin();
    return max - min;
}
