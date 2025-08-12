#ifndef CONTACTS_HPP
#define CONTACTS_HPP
#include <iostream>
#include <string>
#include <unistd.h>

class Contacts{
	private:
	std::string name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	public:

//_______________________SETTERS________________________//

	void set_name(std::string name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_number(std::string phone_number);
	void set_darkest_secret(std::string darkest_secret);

//_______________________GETTERS________________________//
	
	std::string	get_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_darkest_secret();
//________________________CLASS_FUNC_____________________//
	void	print_contact();

};


#endif