#include "phonebook.hpp"

void Contacts::set_name(std::string name) 	{
	this->name = name;
}

void Contacts::set_last_name(std::string last_name){
	this->last_name = last_name;
}

void Contacts::set_nickname(std::string nickname){
	this->nickname = nickname;
}

void Contacts::set_darkest_secret(std::string darkest_secret){
	this->darkest_secret = darkest_secret;
}

void Contacts::set_number(std::string phone_number){
	this->phone_number = phone_number;
}

Contacts *Phonebook::get_contacts(){
	return (contacts);
}

void Phonebook::increment_indexes(){
	this->c_index = (this->c_index + 1) % 8;
	this->s_index += 1;
}

void	Phonebook::init_indexes(){
	this->c_index = 0;
	this->s_index = 0;
}

int	Phonebook::get_index(){
	return (c_index);
}

int	Phonebook::get_s_index(){
	return (s_index);
}

std::string	Contacts::get_name(){
		return (name);
}

std::string Contacts::get_last_name(){
	return (last_name);
}

std::string Contacts::get_nickname(){
	return (nickname);
}

std::string Contacts::get_darkest_secret(){
	return (darkest_secret);
}

std::string Contacts::get_phone_number(){
	return (phone_number);
}