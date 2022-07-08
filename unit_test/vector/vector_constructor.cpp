/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:03:07 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/08 11:43:55 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
//#include "../custom_allocator.hpp"

int	main(void){

	std::allocator<std::string> custom_alloc;
	std::string str;
	int i = 42;
	std::filebuf buf;
	buf.open("logs.txt", std::ios_base::app);
	std::ostream logs(&buf);
	

	//default constructor
	{
	std::vector<int> test;
	}
	{
	std::vector<std::vector<int> > test;
	}
	{
		std::vector<char> test, test1, test2, test3;
	}
	logs << ("Default constructor : OK") << std::endl;
	//allocator constructor
	{
	std::vector<std::string, std::allocator<std::string> > test(custom_alloc);
	}
	logs << ("Allocator constructor : OK") << std::endl;
	//range constructor
	{
		std::istringstream s{"abc"};
    	std::istreambuf_iterator<char> start{s}, end;
		std::vector<char> test2(start, end);
		std::vector<char>::iterator it = test2.begin();
		logs << *it;
		it++;
	}
	logs << ("Range constructor : OK") << std::endl;
	//full constructor
	{
	std::vector<int, std::allocator<int> > test(10, i, custom_alloc);
	}
	logs << ("Full constructor : OK") << std::endl;
	buf.close();
}
