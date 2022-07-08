/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:22:29 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/07 13:15:59 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>
#include <iterator>
#include "sfinae.hpp"

//https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
//source code of <vector> <iterator>

namespace ft{
template<class It>
struct iterator_traits
{
	typedef typename It::difference_type   difference_type;
    typedef typename It::value_type        value_type;
    typedef typename It::pointer           pointer;
    typedef typename It::reference         reference;
    typedef typename It::iterator_category iterator_category;
};

template<class It>
struct iterator_traits<It*>{
	typedef std::ptrdiff_t difference_type;
	typedef It value_type;
	typedef It* pointer;
	typedef It& reference;
	typedef std::random_access_iterator_tag iterator_category;

};

template<class It>
struct iterator_traits<const It*>{
	typedef std::ptrdiff_t difference_type;
	typedef It value_type;
	typedef const It* pointer;
	typedef const It& reference;
	typedef std::random_access_iterator_tag iterator_category;

};

template<class It>
class wrap_iterator{
	
	
	//line 1405 src code 
	public:
		typedef It															iterator_type;
		typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
    	typedef typename iterator_traits<iterator_type>::value_type			value_type;
    	typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
    	typedef typename iterator_traits<iterator_type>::pointer			pointer;
    	typedef typename iterator_traits<iterator_type>::reference			reference; 
	public://constructor
		wrap_iterator() : base_(iterator_type()){};
		
		template<class srcIt>
		wrap_iterator(const wrap_iterator<srcIt>& cpy, typename enable_if<is_same<srcIt, iterator_type>::value>::type* = 0) : base_(cpy.base()){};
		wrap_iterator(const wrap_iterator& cpy) : base_(cpy.base()){};
	public://public method
		iterator_type base() const{
			return base_;
		};
	private://value of the iterator.
		iterator_type base_;

	public:
	//class operator overload	 
    reference operator*() const{
		return *base_;
	};

	pointer operator->() const {
		return base_;
	};

    wrap_iterator& operator++(){
		++base_;
		return *this;
	};

    wrap_iterator  operator++(int) {
		wrap_iterator tmp(*this);
		++(*this);
		return tmp;
	};
	
    wrap_iterator& operator--(){
		--base_;
		return *this;
	};

    wrap_iterator  operator--(int){
		wrap_iterator tmp(*this);
		--(*this);
		return tmp;
	};

    wrap_iterator  operator+ (difference_type n) const{
		wrap_iterator tmp(*this);
		tmp += n;
		return tmp;
	};

	
    wrap_iterator& operator+=(difference_type n){
		*this += n;
		return *this;
	};

   wrap_iterator operator- (difference_type n) const{
	return *this + (-n);
   };

   wrap_iterator& operator-=(difference_type n){
	*this += -n;
	return *this;
   };

   reference operator[](difference_type n) const{
		return base_[n];
   };
};


//external operator overload prototype
template<class it1, class it2>
bool operator==(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs);

template<class it1, class it2>
bool operator<(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs);

template<class it1, class it2>
bool operator!=(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs);

template<class it1, class it2>
bool operator>(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs);

template<class it1, class it2>
bool operator>=(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs);

template<class it1, class it2>
bool operator<=(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs);

template<class it>
bool operator!=(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs);

template<class it>
bool operator>(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs);

template<class it>
bool operator>=(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs);

template<class it>
bool operator<=(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs);

template<class it>
wrap_iterator<it> operator+(typename wrap_iterator<it>::difference_type n, const wrap_iterator<it>& incr_it);

//external operator overload definition
template<class it1, class it2>
inline bool operator==(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs){
	return lhs.base() == rhs.base();
}

template<class it1, class it2>
inline bool operator<(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs){
	return lhs.base() < rhs.base();
}

template<class it1, class it2>
inline bool operator!=(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs){
	return !(lhs == rhs);
}

template<class it1, class it2>
inline bool operator>(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs){
	return rhs.base() < lhs.base();
}

template<class it1, class it2>
inline bool operator>=(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs){
	 return !(lhs.base() < rhs.base());
}

template<class it1, class it2>
inline bool operator<=(const wrap_iterator<it1>& lhs, const wrap_iterator<it2>& rhs){
	 return !(rhs.base() < lhs.base());
}

template<class it>
inline bool operator!=(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs){
	return !(lhs == rhs);
}

template<class it>
inline bool operator>(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs){
	return rhs < lhs;
}

template<class it>
inline bool operator>=(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs){
	return !(lhs < rhs);
}

template<class it>
inline bool operator<=(const wrap_iterator<it>& lhs, const wrap_iterator<it>& rhs){
	return !(rhs < lhs);
}

template<class it>
inline wrap_iterator<it> operator+(typename wrap_iterator<it>::difference_type n, const wrap_iterator<it>& incr_it){
	incr_it += n;
	return incr_it;
}
}
