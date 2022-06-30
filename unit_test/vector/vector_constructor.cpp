/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:03:07 by mafortin          #+#    #+#             */
/*   Updated: 2022/06/29 22:08:45 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <memory>
//#include "../custom_allocator.hpp"

int	main(void){

	std::allocator<std::string> custom_alloc;
	std::string str;
	int i = 42;

	//default
	{
	std::vector<int> test;
	}
	{
	std::vector<std::vector<int> > test;
	}

	//allocator
	{
	std::vector<std::string, std::allocator<std::string> > test(custom_alloc);
	}

	//full
	{
	std::vector<int, std::allocator<int> > test(10, i, custom_alloc);
	}

}