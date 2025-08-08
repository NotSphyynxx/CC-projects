#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <unistd.h>
#include <iomanip>
#include <iostream>
#include "contacts.hpp"

class Phonebook{
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
		void print_contacts() {
			printf("%d\n", this->c_index);
			for (int i = 0; i < s_index; i++) {
				this->contacts[i].print_contact();
			}
		}
};

void	add_contact(Phonebook& phonebook);

#endif