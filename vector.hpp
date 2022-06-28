/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:26 by mafortin          #+#    #+#             */
/*   Updated: 2022/06/27 20:52:34 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
namespace ft{
template<class T, class Allocator = std::allocator<T> >
class vector{
	
	public://public members
		typedef T				value_type;
		typedef Allocator		allocator_type;
		typedef std::size_t		size_type;
		typedef std::ptrdiff_t	difference_type;
		typedef value_type&		reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef const typename Allocator::pointer const_pointer;
		//typedef ?  iterator;
		//typedef ? const_iterator;
		//typedef ? reverse_iterator;
		//typedef ? const_reverse_iterator;
		

	private://private members
	 	allocator_type allocator_;



	public://public methods
	//MEMBER FUNCTIONS
		vector(): allocator_(allocator_type()){//default constructor
			std::cout << "vector default constructor" << std::endl;
		};

		~vector(){
			std::cout << "vector destructor" << std::endl;
			
		};

		vector& operator=(const vector& rhs){
			if (this != rhs){
				std::cout << "vector operator=" << std::endl;
				// put value assignation here
			}
			return *this;
		};

		void	assign(size_type count, const T& value){
			std::cout << "vector assign count,value" << std::endl;
		};

		template< class InputIt >
		void	assign( InputIt first, InputIt last ){//me manque dequoi avec le last. (?)
			std::cout << "vector assign itfirst, itlast" << std::endl;
		};

		allocator_type get_allocator() const{
			std::cout << "vector allocator getter" << std::endl;
			return this->allocator_; //????
		};

	//Element access
		reference at( size_type pos ){
			reference temp(); //test only
			std::cout << "vector at" << std::endl;
			return temp; //test only
		};

		reference operator[](size_type pos){
			reference temp();//test only
			std::cout << "vector operator[]" << std::endl;
			return temp; //test only
		};
		const_reference operator[](size_type pos) const{
			const_reference temp();
			std::cout << "vector operator[] const" << std::endl;
			return temp; //test only
		};
		//TODO front
	//_______________________________________________
	private://private methods
};
}
