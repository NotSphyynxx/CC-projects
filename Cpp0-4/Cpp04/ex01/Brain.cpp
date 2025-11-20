#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain Default Constructor Called !\n";
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "Default";
}

Brain::Brain(const Brain& obj){
    std::cout << "Brain Copy Constructor Called !\n";
    *this = obj;
}

Brain& Brain::operator=(const Brain& obj){
    for (int i = 0; i < 100; i++)
        this->ideas[i] = obj.ideas[i];
    return (*this);
}

Brain::~Brain(){
    std::cout << "Brain Destructor Called !\n";
}