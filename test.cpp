

#include <vector>
#include <memory>
#include "vector.hpp"

int	main(){

	//declaration / constructor
	std::vector<int> std_vector;
	std::vector<int> std_vector_cpy = std_vector;

	ft::vector<int> ft_vector;
	
	//copy assignation test
	ft::vector<int> ft_vector_cpy = ft_vector;

	//assign
	std::cout << "FT TESTING ASSIGN" << std::endl;
	std::size_t count;
	int	it_first;//temp;
	int it_second;//temp
	int content = 0;
	ft_vector.assign(count, content);
	ft_vector.assign(it_first, it_second);

	std::cout << "END OF SCOPE DESTRUCTOR" << std::endl;
}
