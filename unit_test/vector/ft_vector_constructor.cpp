/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_constructor.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:03:07 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/05 12:04:21 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include "../../vector.hpp"

int	main(void){

	std::allocator<std::string> custom_alloc;
	std::string str;
	int i = 42;
	std::filebuf buf;
	buf.open("ft_logs.txt", std::ios_base::app);
	std::ostream logs(&buf);
	

	//default constructor
	{
	ft::vector<int> test;
	}
	{
	ft::vector<ft::vector<int> > test;
	}
	{
		ft::vector<char> test, test1, test2, test3;
	}
	logs << ("Default constructor : OK") << std::endl;
	//allocator constructor
	{
	ft::vector<std::string, std::allocator<std::string> > test(custom_alloc);
	}
	logs << ("Allocator constructor : OK") << std::endl;
	//range construcot
	{

	}
	logs << ("Range constructor : OK") << std::endl;
	//full constructor
	{
	ft::vector<int, std::allocator<int> > test(10, i, custom_alloc);
	}
	logs << ("Full constructor : OK") << std::endl;
	buf.close();
}
