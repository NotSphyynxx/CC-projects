#include "phonebook.hpp"

void	add_contact(Phonebook& phonebook)
{
	std::string input;
	while (1){
		f_name_label:
			std::cout << "Please enter ur first name: ";
			getline(std::cin, input);
			if (std::cin.eof())
				return ;
			if (is_empty(input))
				goto f_name_label;
			phonebook.get_contacts()[phonebook.get_index()].set_name(input);
		l_name_label:
			std::cout << "Please enter ur last name: ";
			getline(std::cin, input);
			if (std::cin.eof())
				return ;
			if (is_empty(input))
				goto l_name_label;
			phonebook.get_contacts()[phonebook.get_index()].set_last_name(input);
		nick_name_label:
			std::cout << "Please enter ur nickname: ";
			getline(std::cin, input);
			if (std::cin.eof())
				return ;
			if (is_empty(input))
				goto nick_name_label;
			phonebook.get_contacts()[phonebook.get_index()].set_nickname(input);
		pb_name_label:
			std::cout << "Please enter ur Phone number: ";
			getline(std::cin, input);
			if (std::cin.eof())
				return ;
			if (is_empty(input) || parse_num(input))
				goto pb_name_label;
			phonebook.get_contacts()[phonebook.get_index()].set_number(input);
		ds_name_label:
			std::cout << "Please enter ur darkest secret: ";
			getline(std::cin, input);
			if (std::cin.eof())
				return ;
			if (is_empty(input))
				goto ds_name_label;
			phonebook.get_contacts()[phonebook.get_index()].set_darkest_secret(input);
		break ;
	}
	std::cout << "Contact added successfully!\n";
	phonebook.increment_indexes();
}

void	search_contacts(Phonebook& phonebook){

	int	i = 0;
	std::string input;

	if (phonebook.get_s_index() == 0){
		std::cout << "There is no contact to search for!\n";
		return ;
	}

	while (i < phonebook.get_s_index()){
		std::cout << std::endl;
		std::cout << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "First Name"
		<< "|" << std::setw(10) << "Last Name"
		<< "|" << std::setw(10) << "Nickname" << std::endl;
		std::cout << std::setw(10) << (i + 1)
		<< "|" << std::setw(10) << (phonebook.get_contacts())[i].get_name()
		<< "|" << std::setw(10) << (phonebook.get_contacts())[i].get_last_name()
		<< "|" << std::setw(10) << (phonebook.get_contacts())[i].get_nickname()
		<< std::endl;
		std::cout << "\n--------------------------------------------\n";
		i++;
	}

	std::cout << "\nPlease enter the contact index to fully see it: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	if (input == "1"){
		(phonebook.get_contacts())[0].print_contact();
	}
	else if (input == "2"){
	(phonebook.get_contacts())[1].print_contact();
	}
	else if (input == "3"){
	(phonebook.get_contacts())[2].print_contact();
	}
	else if (input == "4"){
	(phonebook.get_contacts())[3].print_contact();
	}
	else if (input == "5"){
	(phonebook.get_contacts())[4].print_contact();
	}
	else if (input == "6"){
	(phonebook.get_contacts())[5].print_contact();
	}
	else if (input == "7"){
	(phonebook.get_contacts())[6].print_contact();
	}
	else if (input == "8"){
	(phonebook.get_contacts())[7].print_contact();
	}
	else
		std::cout << "Invalid Index !" << std::endl;
}

int main(){
	std::string input;
	Phonebook phonebook;
	phonebook.init_indexes();
	std::cout << "\n_____________| WELCOME TO PHONEBOOKS.com |____________\n\n";
	while (1)
	{
		if (std::cin.eof())
			return (0);
		std::cout << "\n________| YOU MAY ADD, SEARCH A CONTACT OR EXIT |________\n";
		std::cout << "\n->";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (0);
		if (input == "ADD")
			add_contact(phonebook);
		else if (input == "SEARCH")
			search_contacts(phonebook);
		else if (input == "EXIT"){
			break ;
		}
		else
			continue ;
	}
}