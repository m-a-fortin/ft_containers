

#include <vector>
#include <memory>
#include <string>
#include "vector.hpp"

int	main(){

	//declaration / constructor
	int i = 1;
	std::vector<int> std_vector(10, i);
	std:: cout << "Printing size" << std_vector.size() << std::endl;
	

}
