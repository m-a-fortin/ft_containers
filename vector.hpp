/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:26 by mafortin          #+#    #+#             */
/*   Updated: 2022/06/23 17:30:04 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>

namespace ft{
template<class T, class Allocator = std::allocator<T>
class vector{
	
	public://public members
		typedef T			value_type;
		typedef Allocator	allocator_type;
	private://private members
	 	allocator_type alloc_;



	public://public methods
		vector(): alloc_(allocator_type()){//default constructor

		}

	private://private methods
}
}