


//#include "sfinae.hpp"
#include <iostream>
#include <type_traits>
#include <vector>


template<typename T>
ft::enable_if<std::is_unsigned<T>::value, bool>::type 
	foo(typename T i){
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
}

int	main(){
	int i = 1;
	unsigned int j = 0;

	foo(i);
	foo(j);
}
