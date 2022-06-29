/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:26 by mafortin          #+#    #+#             */
/*   Updated: 2022/06/28 20:18:51 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>

#include "v_iterator.hpp"
#include "reverse_iterator.hpp"

//https://en.cppreference.com/w/cpp/container/vector
namespace ft{
template<class T, class Allocator = std::allocator<T> >
class vector{
	
	public://public members
		typedef T											value_type;
		typedef Allocator									allocator_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef const typename Allocator::pointer			const_pointer;
		typedef v_iterator<pointer, vector>					iterator;
		typedef v_iterator<const_pointer, vector>			const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		

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
			std::cout << "vector assign( count,value )" << std::endl;
		};

		template< class InputIt >
		void	assign( InputIt first, InputIt last ){//me manque dequoi avec le last. (?)
			std::cout << "vector assign( itfirst, itlast)" << std::endl;
		};

		allocator_type get_allocator() const{
			std::cout << "vector allocator getter" << std::endl;
			return this->allocator_; //????
		};

//Element access
		reference at( size_type pos ){
			reference temp(); //test only
			std::cout << "vector at()" << std::endl;
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

		reference front(){
			reference temp();//test only
			std::cout << "vector front()" << std::endl;
			return temp;//test only
		};

		const_reference front() const{
			const_reference temp();
			std::cout << "vector front() const" << std::endl;
			return temp;
		};

		reference back(){
			reference temp();//test only
			std::cout << "vector back()" << std::endl;
			return temp;//test only
		};

		const_reference back() const{
			const_reference temp();
			std::cout << "vector back() const" << std::endl;
			return temp;
		};

		//Returns pointer to the underlying array serving as element storage. The pointer is such that range [data(); data() + size()) is always a valid range, even if the container is empty (data() is not dereferenceable in that case).
		T* data(){
			T* test;
			std::cout << "vector data()" << std::endl;
			return test;
		};

		const T* data() const{
			const T* test;
			std::cout << "vector data()" << std::endl;
			return test;
		};
//Iterators

		//Returns an iterator to the first element of the vector.
		//If the vector is empty, the returned iterator will be equal to end(). 
		iterator begin(){
			iterator test;
			std::cout << "vector begin()" << std::endl;
			return test;
		};

		const_iterator begin() const{
			const_iterator test;
			std::cout << "vector begin() const" << std::endl;
			return test;
		};


		//Returns an iterator to the element following the last element of the vector.
		//This element acts as a placeholder; attempting to access it results in undefined behavior. 
		iterator end(){
			iterator test;
			std::cout << "vector end()" << std::endl;
			return test;
		};

		const_iterator end() const{
			const_iterator test;
			std::cout << "vector end() const" << std::endl;
			return test;
		};

		//Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector.
		//If the vector is empty, the returned iterator is equal to rend(). 
		reverse_iterator rbegin(){
			reverse_iterator test;
			std::cout << "vector rbegin()" << std::endl;
			return test;
		};
		
		const_reverse_iterator rbegin() const{
			const_reverse_iterator test;
			std::cout << "vector rbegin() const" << std::endl;
			return test;
		};

		//Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. 
		//This element acts as a placeholder, attempting to access it results in undefined behavior. 
		reverse_iterator rend(){
			reverse_iterator test;
			std::cout << "vector rend()" << std::endl;
			return test;
		};
		
		const_reverse_iterator rend() const{
			const_reverse_iterator test;
			std::cout << "vector rend() const" << std::endl;
			return test;
		};

//Capacity

		//true if the container is empty, false otherwise 
		bool empty(){
			std::cout << "vector empty()" << std::endl;
			return true;
		};
		
		//Returns the number of elements in the container, i.e. std::distance(begin(), end()). 
		size_type size() const{
			size_type test = 0;
			std::cout << "vector size()" << std::endl;
			return test;
		};



	//_______________________________________________
	private://private methods
};
};
