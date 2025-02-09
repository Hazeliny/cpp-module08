/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:59:51 by linyao            #+#    #+#             */
/*   Updated: 2025/02/09 22:37:36 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    {
        Span	x(5);
        try {
            x.addNumber(6);
		    x.addNumber(3);
		    x.addNumber(17);
		    x.addNumber(9);
		    x.addNumber(11);

		    std::cout << "shortest span: " << x.shortestSpan() << std::endl;
		    std::cout << "longest span:  " << x.longestSpan() << std::endl;
	    }
	    catch (Span::AlreadyFullException &e){
		    std::cout << e.what() << std::endl;
	    }
	    try {
		    x.addNumber(0);
	    }
	    catch (Span::AlreadyFullException &e) {
		    std::cout << e.what() << std::endl;
	    }
    }
    std::cout << std::endl << "*------------------------------*" << std::endl << std::endl;
	{
		Span s = Span(6);
		for (size_t i = 0; i < 7; i++)
		{
			try
			{
				s.addNumber(i + 2);
			}
			catch (Span::AlreadyFullException &e)
			{
				std::cerr << e.what() << std::endl;
			}
		}
		std::cout << "shortest span is " << s.shortestSpan() << std::endl;
		std::cout << "longest span is " << s.longestSpan() << std::endl;
	}
	std::cout << std::endl << "*------------------------------*" << std::endl << std::endl;
	{
		Span a = Span(20000);
		a.addNumberOnce(20000, time(NULL));
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl << std::endl;
	}
    std::cout << std::endl << "*------------------------------*" << std::endl << std::endl;
    {
		Span c = Span(1);
        try
        {
		    c.addNumber(11);
            std::cout << "shortest span is " << c.shortestSpan() << std::endl;
		    std::cout << "longest span is " << c.longestSpan() << std::endl;
        }
        catch(Span::OnlyOneException& e)
        {
            std::cerr << e.what() << std::endl;
            std:: cout << std::endl;
        }
	}
/*
	{
		Span b = Span(15000);
        try
        {
		    b.addNumberOnce(18000, time(NULL));
        }
        catch(Span::AlreadyFullException& e)
        {
            std::cerr << e.what() << std::endl;
        }
		std::cout << "shortest span is " << b.shortestSpan() << std::endl;
		std::cout << "longest span is " << b.longestSpan() << std::endl << std::endl;
	}
    std::cout << std::endl << "*------------------------------*" << std::endl << std::endl;
*/
/*
    std::cout << std::endl << "*------------------------------*" << std::endl << std::endl;
	{
		Span d = Span(0);
        try
        {
//		    d.addNumber(11);
            std::cout << "shortest span is " << d.shortestSpan() << std::endl;
		    std::cout << "longest span is " << d.longestSpan() << std::endl;
        }
        catch(Span::OnlyOneException& e)
        {
            std::cerr << e.what() << std::endl;
            std:: cout << std::endl;
        }
	}
*/
    return 0;
}
