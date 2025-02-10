/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:59:51 by linyao            #+#    #+#             */
/*   Updated: 2025/02/10 22:33:52 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main( void )
{
	std::cout << "*------------------------------*" << std::endl;
	std::cout << "Testing MutantStack..." << std::endl;
	std::cout << "*------------------------------*" << std::endl;
    {
        MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
    }
    std::cout << "*------------------------------*" << std::endl;
	std::cout << "Testing std::list..." << std::endl;
	std::cout << "*------------------------------*" << std::endl;
	{
		std::list<int> l;
		l.push_back(5);
		l.push_back(17);
		std::cout << l.back() << std::endl;
		l.pop_back();
		std::cout << l.size() << std::endl;
		l.push_back(3);
		l.push_back(5);
		l.push_back(737);
		l.push_back(0);
		std::list<int>::iterator it = l.begin();
		std::list<int>::iterator ite = l.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> x(l);
	}

    return 0;
}
