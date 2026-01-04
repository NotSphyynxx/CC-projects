#include "iter.hpp"

void print_arr(const int arr){
	std::cout << arr << std::endl;
}

int main(){
	const int a[7] = {1,2,3,4,5,6,7};
	iter(a, 7, print_arr);
	char str[4];
	str[0] = 'i';
	str[1] = 's';
	str[2] = 'm';
	str[3] = 0;
	iter(str, 4, print_arr);
}