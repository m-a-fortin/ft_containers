/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterator.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:05:58 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/05 14:14:11 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <iterator>
#include "../../iterator.hpp"
#include "../../vector.hpp"

int	main(void){

	std::filebuf buf;
	buf.open("ft_logs.txt", std::ios_base::app);
	std::ostream logs(&buf);

	std::vector<int> test;
	std::vector<int> test2;
	
	test2.push_back(1);
	for(int i = 1; i < 100; i++){
		test.push_back(i);
	}

	{
	logs << "Allocating vector iterator" << std::endl;
	int *s = NULL;
	std::vector<int>::iterator it;
	std::allocator<int> alloc = test.get_allocator();
	alloc.allocate(1, &it);
	logs << "Assigning iterator to test vector" << std::endl;
	//*it = test[2];
	logs << *it << std::endl;
	it = test.begin();
	logs << "it +=\n";
	it += 98;
	logs << *it << std::endl;
	it += 1;
	logs << *it << std::endl;
	//*it = test[2];
	logs << *it << std::endl;
	it = test.begin();
	logs << "Looping on vector" << std::endl;
	while (it != test.end()){
		logs << *it << std::endl;
		it++;
	}
	logs << *it << std::endl;
	it = test.begin();
	logs << "Vector iterator cpy constructor" << std::endl;
	std::vector<int>::iterator it_cpy(it);
	logs << "Looping on cpy\n";
	while (it_cpy != test.end()){
		logs << *it_cpy << "\n";
		it_cpy++;
	}
	logs << std::flush;
	//logs << "Reverse iterator with vector iterator\n";
	//std::reverse_iterator<std::vector<int>::iterator> r_it;
	//r_it = test.rbegin();
	//logs << "Looping on vector with reverse it (r_it++)\n";
	//while (r_it != test.rend()){
	//	logs << *r_it << "\n";
	//	r_it++;
	//}
	logs << "Testing vector iterator operator overload\n";
	it = test.begin();
	logs << "operator *\n";
	logs << "*it = " << *it << "\n";
	logs << "operator =\n";
	it_cpy = it;
	logs << "rhs = " << *it << " lhs = " << *it_cpy << "\n";
	logs << "operator ==\n";
	if (it == it_cpy){
		logs << "it is == to it_cpy\n";
	}
	logs << "operator ++ && ++(int)\n";
	logs << "it++ = " << *(it++) << "\n" << "After = " << *it << "\n";
	logs << "++it = " << *(++it) << "\n" << "After = " << *it << "\n";
	logs << "operator + 10\n";
	logs << "it + 10 = " << *(it + 10) << "\n";
	logs << "operator -- && --(int)\n";
	logs << "it-- = " << *(it--) << "\n" << "After = " << *it << "\n";
	logs << "--it = " << *(--it) << "\n" << "After = " << *it << "\n";
	logs << "operator - 10\n";
	logs << "it - 10 = " << *(it - 10) << "\n";
	logs << "operator +=\n";
	logs << "it += 10 = " << *(it += 10) << "\n";
	logs << "operator -=\n";
	logs << "it -= 10 = " << *(it -= 10) << "\n";
	logs << "operator ->\n";
	std::vector<int>::iterator *ptr_it;
	ptr_it = new std::vector<int>::iterator(it);
	logs << "ptr_it->base() = " << *(ptr_it->base()) << " " << ptr_it->base() << "\n";
	logs << "it.base() = " << *(it.base()) << " " << it.base() << "\n";
	delete ptr_it;
	logs << "operator []\n";
	logs << "it[0] = " << it[0] << " | it[10] = " << it[10] << "\n";

	}
	
	buf.close();
}
