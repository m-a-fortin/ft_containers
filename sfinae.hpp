/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfinae.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:47:54 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/04 18:22:20 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

//exemple de enable_if
/*template<typename T>
typename ft::enable_if<std::is_unsigned<T>::value, bool>::type
 foo(T i){
	std::cout << "UNSIGNED" << std::endl;
	return true;
}

bool	foo(int i){
	std::cout << "SIGNED" << std::endl;
	return false;
	
}



int	main(){
	int i = 1;
	unsigned int j = 0;

	foo(i);
	foo(j);
}*/

//SFINAE
//Substitution Failure Is Not An Error
namespace ft{

template<bool, class T = void>
struct enable_if{};

template<class T>
struct enable_if<true, T>{
	typedef T type;
};

template<class T, class J>
struct is_convertible{
	static const bool value = false;
};
template<class T>
struct is_convertible<T, T>{
	static const bool value = true;
};

template<class T>
struct is_integral{
	static const bool value = false;
};

template<>
struct is_integral<char>{
	static const bool value = true;
};

template<>
struct is_integral<signed char>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned char>{
	static const bool value = true;
};

template<>
struct is_integral<int>{
	static const bool value = true;
};

template<>
struct is_integral<unsigned int>{
	static const bool value = true;
};

template<>
struct is_integral<short int>{
	static const bool value = true;
};


template<>
struct is_integral<long int>{
	static const bool value = true;
};


template<>
struct is_integral<unsigned long int>{
	static const bool value = true;
};


};
