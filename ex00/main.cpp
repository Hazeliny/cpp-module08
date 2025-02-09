/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:59:51 by linyao            #+#    #+#             */
/*   Updated: 2025/02/09 20:15:21 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <cstdlib>
#include "easyfind.hpp"

int main( void )
{
    std::vector<int>    int_vec;
    std::list<int>      int_list;
    srand(time(NULL));
    for (int i = 0; i < 20; i++)
    {
        int_vec.push_back(rand() % 20);
        int_list.push_front(rand() % 20);
    }
    std::cout << "The content of vector:" << std::endl;
    print(int_vec);
    std::cout << "*------------------------------*" << std::endl;

    int num = 15;
    try
    {
        std::cout << "Search integer: " << num << std::endl;
        std::vector<int>::iterator it = easyfind(int_vec, num);
        std::cout << "Integer " << *it << " founded" << std::endl;
    }
    catch(const NotFoundException &e)
    {
        std::cerr << "Integer " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "*------------------------------*" << std::endl;
    std::cout << "The content of list:" << std::endl;
    print(int_list);
    std::cout << std::endl;
    try
    {
        std::cout << "Search integer: " << num << std::endl;
        std::list<int>::iterator it = easyfind(int_list, num);
        std::cout << "Integer " << *it << " founded" << std::endl;
    }
    catch(const NotFoundException &e)
    {
        std::cerr << "Integer " << e.what() << std::endl;
    }
 
    return 0;
}
