


#include "sfinae.hpp"
#include <iostream>
#include <type_traits>


template<class T>
void	foo(T){
	std::cout << "SIGNED" << std::endl;
}

template<class T, typename std::enable_if<std::is_unsigned<T>::value, T>::type last>
void	foo(T){
	std::cout << "UNSIGNED" << std::endl;
}


int	main(){
	int i = 1;
	unsigned int j = 0;

	foo(i);
	foo(j);
}