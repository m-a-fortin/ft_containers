/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:03:14 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/01 18:03:31 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <fstream>
#include <memory>

int	main(void){

	std::filebuf buf;
	buf.open("logs.txt", std::ios_base::app);
	std::ostream logs(&buf);

	std::vector<int> test;
	std::vector<int> test2;
	
	test2.push_back(1);
	for(int i = 1; i < 100; i++){
		test.push_back(i);
	}

	{
	logs << "ALLOCATING VECTOR ITERATOR" << std::endl;
	int *s = NULL;
	std::vector<int>::iterator it;
	std::allocator<int> alloc = test.get_allocator();
	alloc.allocate(1, &it);
	logs << "ASSIGNING ITERATOR TO TEST VECTOR INDEX" << std::endl;
	*it = test[2];
	logs << *it << std::endl;
	it = test.begin();
	it += 98;
	logs << *it << std::endl;
	it += 1;
	logs << *it << std::endl;
	*it = test[2];
	logs << *it << std::endl;
	it = test.begin();
	while (it != test.end()){
		logs << *it << std::endl;
		it++;
	}
	}
	
	buf.close();
}