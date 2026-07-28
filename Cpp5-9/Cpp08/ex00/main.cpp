#include "easyfind.hpp"

const char* NotFound::what() const throw() {
    return "Error: Value not found";
}

int main(){
    // int arr[] = {10, 20, 30, 40};
    std::vector<int> v;
    // WITH SUCCESS
    try {
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);
        // std::cout  << "Vector Cap: "<< v.capacity() << "\n" << "Vector Size: "<< v.size() << std::endl;
        std::vector<int>::iterator it = easyFind(v, 40);
        std::cout << "Value Found !! : " << *it << std::endl;
    }
    catch (std::exception &except){
        std::cout << except.what() << std::endl;
    }
    // WITH ERROR
        try {
        std::vector<int>::iterator it = easyFind(v, 70);
        std::cout << "Value Found !! : " << *it << std::endl;
    }
    catch (std::exception &except){
        std::cout << except.what() << std::endl;
    }
    return 0;
}