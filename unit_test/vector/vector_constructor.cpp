/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:03:07 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/07 16:46:41 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <iterator>
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
		std::vector<int> test;
		for (std::size_t i = 0; i < 100; i++){
			test.push_back(i + 1);
		}
		std::input_iterator<int> it;
		
		std::vector<int> test2()
	}
	logs << ("Range constructor : OK") << std::endl;
	//full constructor
	{
	std::vector<int, std::allocator<int> > test(10, i, custom_alloc);
	}
	logs << ("Full constructor : OK") << std::endl;
	buf.close();
}
