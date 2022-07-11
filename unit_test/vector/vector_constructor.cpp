/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:03:07 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/11 12:13:34 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <forward_list>
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
		logs << "\nTesting range constructor value\n______________\n";

		logs << "Input Iterator (isstringstream) :\n";
		{
		std::istringstream s("Hello Vector Unit Test\n");
    	std::istreambuf_iterator<char> start(s), end;
		std::vector<char> test2(start, end);
		std::vector<char>::iterator it = test2.begin();
		for(std::vector<char>::iterator it = test2.begin(); it != test2.end(); ++it){
			logs << *it;
		}
		}
		logs << "Forward Iterator (std::forward_list) :\n";
		{
			std::forward_list<int> f_list;
			for (int i = 0; i < 10; i++){
			f_list.push_front(i);
			}
			std::forward_list<int>::iterator start = f_list.begin();
			std::forward_list<int>::iterator end = f_list.end();

			std::vector<int> test2(start, end);
			for (std::vector<int>::iterator it = test2.begin(); it != test2.end(); ++it){
				logs << *it;
			}
			logs << std::endl;
			
		}
	}
	logs << ("Range constructor : OK") << std::endl;
	//full constructor
	{
	std::vector<int, std::allocator<int> > test(10, i, custom_alloc);
	}
	logs << ("Full constructor : OK") << std::endl;
	buf.close();
}
