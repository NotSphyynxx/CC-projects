#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <iostream>
#include "contacts.hpp"

class Phonebook {
	private:
		int	c_index;
		Contacts contacts[8];
		int s_index;
		int contact_count;

	public:
		void 		increment_indexes();
		int  		get_index();
		void 		init_indexes();
		Contacts	*get_contacts();
		int			get_s_index();
};

void	add_contact(Phonebook& phonebook);
int		is_empty(std::string input);

#endif