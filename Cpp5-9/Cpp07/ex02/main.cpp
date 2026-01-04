#include "Array.hpp"


int main(){
	Array<int> copy_array(10);
	for (unsigned int i = 0;i < copy_array.size();i++){
		copy_array[i] = i;
	}
	Array<int> int_array(copy_array);
	for (unsigned int i = 0;i < int_array.size();i++){
		std::cout << "[" << int_array[i] << "]" << std::endl;
	}
	// exception error
	Array<int> array(10);
	for (unsigned int i = 0;i < array.size();i++){
		array[i] = i + 1;
	}
	try {
		array[999];
	}
	catch(std::runtime_error &excep){
		std::cout << excep.what() << std::endl;
	}
	std::cout << array[9] << std::endl;
	return (0);
}
