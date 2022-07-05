/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:26 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/05 17:27:40 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


//STD
#include <memory>
#include <iostream>
#include <algorithm>
#include <limits>
#include <stdexcept>

//FT
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "sfinae.hpp"


//https://en.cppreference.com/w/cpp/container/vector
//vector is a sequence container that encapsulates dynamic size arrays.
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
		typedef const typename Allocator::const_pointer		const_pointer;
		typedef wrap_iterator<pointer>						iterator;
		typedef wrap_iterator<const_pointer>				const_iterator;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		

	private://private members
	 	allocator_type allocator_;
		pointer start_;
		pointer end_;
		pointer capacity_end_;

	public://public methods
//MEMBER FUNCTIONS
		vector(): allocator_(allocator_type()), start_(NULL), end_(NULL), capacity_end_(NULL){};//clean

		explicit vector( const allocator_type& alloc ): allocator_(alloc), start_(NULL), end_(NULL), capacity_end_(NULL){};//clean

		explicit vector( size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()): 
		allocator_(alloc){
			if (count == 0){
				start_ = NULL;
				end_= NULL;
				capacity_end_ = NULL;
				return ;
			}
			start_ = allocator_.allocate(count);
			capacity_end_ = start_ + count;
			end_ = capacity_end_;
			fill_range(start_, end_, value);
		};

		template< class InputIt >
	 vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type() ) : allocator_(alloc){
			std::cout << "vector(first, last, alloc = Allocator()) constructor" << std::endl;
		};
		
		vector( const vector& other ){
			std::cout << "vector(other) constructor" << std::endl;
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
			return static_cast<size_type>(end_ - start_);
		};

		//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(begin(), end()) for the largest container. 
		size_type max_size() const{
			return static_cast<size_type>(std::numeric_limits<difference_type>::max());
		};

		//Increase the capacity of the vector 
		void reserve( size_type new_cap ){
			(void)new_cap;
			std::cout << "vector size_type()" << std::endl;
		};
		//Modifiers

		//Erases all elements from the container. After this call, size() returns zero. 
		void clear(){
			std::cout << "vector clear()" << std::endl;
		}
		
		//Inserts elements at the specified location in the container. See cppreference for overload diff.
		iterator insert(iterator pos, const T& value){
			iterator test;
			std::cout << "vector insert(pos, value)" << std::endl;
			return test;
		};

		void insert(iterator pos, size_type count, const T& value){
			(void)pos;
			(void)count;
			(void)value;
			std::cout << "vector insert(pos, count, value)" << std::endl;
		};

		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last ){
			(void)pos;
			(void)first;
			(void)last;
			std::cout << "vector insert(pos, first, last)" << std::endl;
		};
		
		//Erases the specified elements from the container. 
		iterator erase( iterator pos){
			std::cout << "vector erase(pos)" << std::endl;
			return pos;//to be removed
		};
		
		iterator erase( iterator first, iterator last ){
			(void)first;
			(void)last;
			std::cout << "vector erase(first, last)" << std::endl;
			return first;//to be removed
		};

		//Appends the given element value to the end of the container. 
		void push_back(const T& value){
			(void)value;
			std::cout << "vector push_back(value)" << std::endl;
		};

		//Removes the last element of the container. 
		void pop_back(){
			std::cout << "vector pop_back()" << std::endl;
		};

		//Resizes the container to contain count elements. 
		void resize(size_type count){
			(void)count;
			std::cout << "vector resize()" << std::endl;
		};

		void resize( size_type count, T value = T() ){
			std::cout << "vector resize(count, T value = T()" << std::endl;
		};
		
		//Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements. 
		void swap(vector& other){
			(void)other;
			std::cout << "vector swap()" << std::endl;
		}
		
		size_type capacity() const{
			return static_cast<size_type>(capacity_end_ - start_);
		};
	//_______________________________________________
	private://private methods
		void fill_range(pointer start, const_pointer end, const_reference value){
			for (; start != end; ++start){
				allocator_.construct(start, value);
			}
		}
		
		/*template< class InputIt >
		void fill_range(InputIt first, InputIt last){
			for(; first != last; ++first){
				allocator_.construct(first, *first);
			}
		};TODO MAYBE*/


		//return the difference between the capacity end ptr and the start

		//return the new capacity (either size + nb_elem to add or capacity * 2)
		//throw if size is bigger than max_size
		size_type new_capacity(size_type new_size) const{
			const size_type max = max_size();
			if (new_size > max)
				throw std::length_error("vector");
			const size_type cap = capacity();
			if (cap >= max / 2)
				return max;
			
			return std::max(new_size, cap * 2);
		};
		
		//private method prototype
		iterator make_iter(pointer p);
		const_iterator make_iter(const_pointer p);
};

//return a iterator with a ptr
template<class Tp, class Alloc>
inline typename vector<Tp, Alloc>::iterator vector<Tp, Alloc>::make_iter(pointer p){
	return iterator(p);
}

//return a const_iterator with a const_ptr
template<class Tp, class Alloc>
inline typename vector<Tp, Alloc>::const_iterator vector<Tp, Alloc>::make_iter(const_pointer p){
	return const_iterator(p);
}
};

