/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:10:11 by linyao            #+#    #+#             */
/*   Updated: 2025/02/09 20:17:22 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
//#include <string>
//#include <cmath>

class NotFoundException: public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return ("Not found");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int i)
{
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it == container.end())
        throw (NotFoundException());
    return it;
}

template <typename T>
void print(T &container)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
