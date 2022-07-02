/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfinae.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafortin <mafortin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:47:54 by mafortin          #+#    #+#             */
/*   Updated: 2022/07/01 19:31:59 by mafortin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

namespace ft{

template<bool, class T = void>
struct enable_if{};

template<class T>
struct enable_if<true, T>{
	typedef T type;
};

};
