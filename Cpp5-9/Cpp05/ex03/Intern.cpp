#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) {
	(void)obj;
}

Intern&	Intern::operator=(const Intern& obj){
	(void)obj;
	return (*this);
}

Intern::~Intern() {}

AForm* makeRobotomyRequest(std::string target){
	return (new RobotomyRequestForm(target));
}

AForm* makePresidentialPardon(std::string target){
	return (new PresidentialPardonForm(target));
}

AForm* makeShrubberyCreation(std::string target){
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string target){
	AForm* (*fptr[])(std::string target) = {
		&makeRobotomyRequest,
		&makePresidentialPardon,
		&makeShrubberyCreation
	};
	std::string forms[] = {"robotomy request", "Presidential pardon", "Shrubbery creation"};
	for (int i = 0;i < 3;i++){
		if (forms[i] == formName){
			std::cout << "Intern creates " + formName << std::endl;
			return (fptr[i](target));
		}
	}
	std::cout << "Intern failed to create " + formName << std::endl;
	return (NULL);
}