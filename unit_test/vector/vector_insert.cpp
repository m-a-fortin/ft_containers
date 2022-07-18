/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_insert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:16:30 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/18 11:28:36 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>


int	main(){

	std::filebuf buf;
	buf.open("logs.txt", std::ios_base::app);
	std::ostream logs(&buf);
	logs << "----------VECTOR INSERT----------\n";
	{
	std::vector<int> test1;
	test1.reserve(20);
	logs << "Pushing 10 #\n";
	for(int i = 0; i < 10; ++i){
		test1.push_back(i);
		logs << test1[i] << "\n";
	}
	std::vector<int>::iterator it = test1.begin() + 5;
	test1.insert(it, 5, 42);
	logs << "Inserting 5x number 42 at begin + 5\n";
	for(std::vector<int>::iterator it = test1.begin(); it != test1.end(); ++it){
		logs << *it << "\n";
	}
	}
	logs << "Empty vector + insert 42 x 10 at begin\n";
	{
		std::vector<int> test1;
		test1.insert(test1.begin(), 10, 42);
		for(std::vector<int>::iterator it = test1.begin(); it != test1.end(); ++it){
		logs << *it << "\n";
	}
	}
	{
		logs << "Vector with capacity of 5. Insert 10 elem.\n";
		std::vector<int> test1;
		test1.reserve(5);
		test1.insert(test1.begin(), 10, 42);
		for(std::vector<int>::iterator it = test1.begin(); it != test1.end(); ++it){
		logs << *it << "\n";
	}
	}
	buf.close();
}