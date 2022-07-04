/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:22:29 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/04 19:05:04 by mafortin         ###   ########.fr       */
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
	public:
		wrap_iterator() : it_(iterator_type()){};
		
		template<class upIt>
		wrap_iterator(const wrap_iterator<upIt>& src, typename enable_if<is_convertible<upIt, iterator_type>::value>::type* = 0) : it_(src.it_){}

	private:
		iterator_type it_;
};

};
