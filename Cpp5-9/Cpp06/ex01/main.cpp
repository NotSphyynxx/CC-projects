#include "Serializer.hpp"

int main(){
	Data person;
	person.age = 20;
	person.name = "Sphynx";
	uintptr_t raw;
	raw = Serializer::serialize(&person);
	Data *ptr1 = Serializer::deserialize(raw);
	std::cout << ptr1->age  << "\n" << ptr1->name << "\n";
}