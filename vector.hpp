/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:20:26 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/06 14:24:33 by mafortin         ###   ########.fr       */
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
		};

	 template< class InputIt >
	 vector(InputIt first, typename enable_if<!is_integral<InputIt>::value, InputIt>::type end, const Allocator& alloc = Allocator() ) : allocator_(alloc){

		};
		
		vector( const vector& other ){
			const size_type other_size = other.capacity();
			if (v_size > 0){
				allocator_ = other.allocator_;
				this->start_ = allocator_.allocate(other_size);
			}
			else{
				vector();
			}
		};
		
		~vector(){
			delete_vector();
		};

		vector& operator=(const vector& rhs){
			if (this != rhs){
				
			}
			return *this;
		};

		void	assign(size_type count, const T& value);

		template< class InputIt >
		void	assign( InputIt first, InputIt last ){//me manque dequoi avec le last. (?)
			std::cout << "vector assign( itfirst, itlast)" << std::endl;
		};

		allocator_type get_allocator() const{
			return this->allocator_;
		};

//Element access
		reference at( size_type pos ){
			if (pos >= size()){
				std::length_error("vector");
			}
			return (*this)[pos];
		};

		reference operator[](size_type pos){
			return *(start_ + pos);
		};

		const_reference operator[](size_type pos) const{
			return *(start_ + pos);
		};

		reference front(){
			return *begin();
		};

		const_reference front() const{
			return *begin();
		};

		reference back(){
			return *end();
		};

		const_reference back() const{
			return *end();
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
			return iterator(start_);
		};

		const_iterator begin() const{
			return const_iterator(start_);
		};


		//Returns an iterator to the element following the last element of the vector.
		//This element acts as a placeholder; attempting to access it results in undefined behavior. 
		iterator end(){
			return iterator(end_);
		};

		const_iterator end() const{
			return const_iterator(end_);
		};

		//Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector.
		//If the vector is empty, the returned iterator is equal to rend(). 
		reverse_iterator rbegin(){
			return reverse_iterator(end());
		};
		
		const_reverse_iterator rbegin() const{
			return const_reverse_iterator(end());
		};

		//Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. 
		//This element acts as a placeholder, attempting to access it results in undefined behavior. 
		reverse_iterator rend(){
			return reverse_iterator(start());
		};
		
		const_reverse_iterator rend() const{
			return const_reverse_iterator(start());
		};

//Capacity

		//true if the container is empty, false otherwise 
		bool empty() const{
			return (this->start_ == this->end_);
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
			if (new_cap > max_size()){
				std::length_error("vector");
			}
			if (new_cap > capacity()){
				pointer new_start = allocator_.allocate(new_cap);
				pointer new_end = cpy_range(new_start, this->start_, this->end_);
				clear();
				this->start_ = new_start;
				this->end_ = new_end;
				this->capacity_end_ = this->start_ + new_cap;
			}
		};
		//Modifiers

		//Erases all elements from the container. After this call, size() returns zero. 
		void clear(){
			delete_range(this->start_, this->end_);
			this->end_ = this->start_;
		}
		
		//Inserts elements at the specified location in the container. See cppreference for overload diff.
		iterator insert(iterator pos, const_reference value){
			
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

		//fill with value every pointer between start and end.
		void fill_range(pointer start, pointer end, const_reference value){
			for (; start != end; ++start){
				allocator_.construct(start, value);
			}
		}

		//cpy the value of original vector pointers too new pointers and return the new end.
		pointer	cpy_range(pointer new_start, pointer start, pointer end){
			for(;start != end; ++start){
				allocator_.construct(new_start, *start);
				++new_start;
			}
			return new_start;
		}

		void	delete_range(pointer start, pointer end){
			for(; start != end; ++start){
				allocator_.destroy(start);
			}
		}

		void	delete_vector(){
			if (this->start_ != NULL){
				delete_range(this->start_, this->end_);
				allocator_.deallocate(this->start_, capacity());
			}
		}
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

//return a iterator with a ptr as argument
template<class Tp, class Alloc>
inline typename vector<Tp, Alloc>::iterator vector<Tp, Alloc>::make_iter(pointer p){
	return iterator(p);
}

//return a const_iterator with a const_ptr as argument
template<class Tp, class Alloc>
inline typename vector<Tp, Alloc>::const_iterator vector<Tp, Alloc>::make_iter(const_pointer p){
	return const_iterator(p);
}
};

